#ifndef __KEYBOARD_H
#define __KEYBOARD_H

#include "stdint.h"

#define LINE_1 GPIO_PIN_3
#define LINE_2 GPIO_PIN_2
#define LINE_3 GPIO_PIN_1
#define LINE_4 GPIO_PIN_0

#define ROW_4 GPIO_PIN_7
#define ROW_3 GPIO_PIN_6
#define ROW_2 GPIO_PIN_5
#define ROW_1 GPIO_PIN_4

#define READ_ROW_1 HAL_GPIO_ReadPin(GPIOA,ROW_1)
#define READ_ROW_2 HAL_GPIO_ReadPin(GPIOA,ROW_2)
#define READ_ROW_3 HAL_GPIO_ReadPin(GPIOA,ROW_3)
#define READ_ROW_4 HAL_GPIO_ReadPin(GPIOA,ROW_4)
 
uint16_t scale_keyboard(void);
uint8_t whether_to_press(void);
void wirte_line_pin_state(uint8_t line_1,uint8_t line_2,uint8_t line_3,uint8_t line_4);

#endif