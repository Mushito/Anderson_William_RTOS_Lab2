/*
 * Application_Code.h
 *
 *  Created on: Jan 27, 2026
 *      Author: willa
 */

#ifndef INC_APPLICATION_CODE_H_
#define INC_APPLICATION_CODE_H_

#include <stm32f4xx_hal.h>
#include <stm32f4xx.h>
#include <Gyro_Driver.h>

#define GREEN_LED_PIN 	GPIO_PIN_13
#define RED_LED_PIN   	GPIO_PIN_14
#define USER_BUTTON_PIN GPIO_PIN_0

#define RED_LED_PORT     GPIOG
#define GREEN_LED_PORT   GPIOG
#define USER_BUTTON_PORT GPIOA

#define SLOW_THRESHOLD = 500.0f;
#define FAST_THRESHOLD = 2000.0f;
#define ZERO_THRESHOLD = 10.0f;

#define LAB2_USE_INTERRUPT 0


typedef enum {
    GYRO_NONE = 0,   
    GYRO_SLOW_CW,
    GYRO_FAST_CW,
    GYRO_SLOW_CCW,      
    GYRO_FAST_CCW,
	GYRO_ERROR
} Gyro_Direction_t;

volatile uint8_t button_Pressed = 0; 
volatile Gyro_Direction_t gyro_Direction = GYRO_NONE;


void sampleUserButton();

Gyro_Direction_t getGyroDirection(void);

void drive_LED(Gyro_Direction_t dir);

#endif /* INC_APPLICATION_CODE_H_ */
