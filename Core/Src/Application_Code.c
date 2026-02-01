/*
 * Application_Code.c
 *
 *  Created on: Jan 27, 2026
 *      Author: willa
 */

#include "Application_Code.h"

void sampleUserButton(){
    if  (HAL_GPIO_ReadPin(USER_BUTTON_PORT, USER_BUTTON_PIN == GPIO_PIN_SET));
        button_Pressed = 1;
    else button_Pressed = 0;
}

Gyro_Direction_t getGyroDirection(void){
    float angVel = Gyro_Get_Velocity();

    if (angVel > FAST_THRESHOLD)
        return GYRO_FAST_CW;
    else if (angVel > SLOW_THRESHOLD)
        return GYRO_SLOW_CW;
    else if(angVel < ZERO_THRESHOLD && angVel > -ZERO_THRESHOLD)
        return GYRO_NONE;
    else if (angVel < -SLOW_THRESHOLD)
        return GYRO_SLOW_CCW;
    else if (angVel < -FAST_THRESHOLD)
        return GYRO_FAST_CCW;
    else return GYRO_ERROR;
}

void drive_LED(Gyro_Direction_t dir){
    if (button_Pressed || dir == GYRO_SLOW_CCW || dir == GYRO_FAST_CCW)
        HAL_GPIO_WritePin(GREEN_LED_PORT, GREEN_LED_PIN, GPIO_PIN_SET);
    else HAL_GPIO_WritePin(GREEN_LED_PORT, GREEN_LED_PIN, GPIO_PIN_RESET);

    if(button_Pressed && (dir == GYRO_FAST_CW || dir == GYRO_SLOW_CW))
        HAL_GPIO_WritePin(RED_LED_PORT, RED_LED_PIN, GPIO_PIN_SET);
    else HAL_GPIO_WritePin(RED_LED_PORT, RED_LED_PIN, GPIO_PIN_RESET);
}