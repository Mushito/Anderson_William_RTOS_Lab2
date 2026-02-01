/*
 * Application_Code.h
 *
 *  Created on: Jan 27, 2026
 *      Author: willa
 */

#ifndef INC_APPLICATION_CODE_H_
#define INC_APPLICATION_CODE_H_

typedef enum {
    GYRO_NONE = 0,   
    GYRO_SLOW_CW,
    GYRO_FAST_CW,
    GYRO_SLOW_CCW,      
    GYRO_FAST_CCW       
} Gyro_Direction_t;

volatile uint8_t button_Pressed = 0; 
volatile Gyro_Direction_t g_Gyro_Direction = GYRO_NONE;

void sampleUserButton();

Gyro_Direction_t getGyroDirection(void);

void drive_LED(Gyro_Direction_t dir);

#endif /* INC_APPLICATION_CODE_H_ */
