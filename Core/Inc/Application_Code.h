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

#define SLOW_THRESHOLD 10000.0f
#define FAST_THRESHOLD 20000.0f
#define ZERO_THRESHOLD 75.0f

#define LAB2_USE_INTERRUPT 0

typedef enum {
    GYRO_NONE = 0,
    GYRO_SLOW_CW,
    GYRO_FAST_CW,
    GYRO_SLOW_CCW,
    GYRO_FAST_CCW,
	GYRO_ERROR
} Gyro_Direction_t;

extern volatile uint8_t button_Pressed;
extern volatile Gyro_Direction_t gyro_Direction;

void sampleUserButton();

Gyro_Direction_t getGyroDirection(void);

void drive_LED(Gyro_Direction_t dir);

#endif /* INC_APPLICATION_CODE_H_ */
