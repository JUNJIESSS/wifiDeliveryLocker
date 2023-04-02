#include "keyboard.h"
#include "gpio.h"

uint8_t last_value;
uint8_t value;

uint16_t scale_keyboard()
{
	wirte_line_pin_state(0,1,1,1);
	
	if(READ_ROW_1==0||READ_ROW_2==0||READ_ROW_3==0||READ_ROW_4==0)
	{

		if(HAL_GPIO_ReadPin(GPIOA,ROW_1)==0)return 1;
		if(HAL_GPIO_ReadPin(GPIOA,ROW_2)==0)return 2;
		if(HAL_GPIO_ReadPin(GPIOA,ROW_3)==0)return 3;
		if(HAL_GPIO_ReadPin(GPIOA,ROW_4)==0)return 4;
	}
	else
	{
		wirte_line_pin_state(1,0,1,1);
		
		if(READ_ROW_1==0||READ_ROW_2==0||READ_ROW_3==0||READ_ROW_4==0) //the seconde line
		{
			if(HAL_GPIO_ReadPin(GPIOA,ROW_1)==0)return 5;
			if(HAL_GPIO_ReadPin(GPIOA,ROW_2)==0)return 6;
			if(HAL_GPIO_ReadPin(GPIOA,ROW_3)==0)return 7;
			if(HAL_GPIO_ReadPin(GPIOA,ROW_4)==0)return 8;
		}
		else
		{
			wirte_line_pin_state(1,1,0,1);
			
			if(READ_ROW_1==0||READ_ROW_2==0||READ_ROW_3==0||READ_ROW_4==0) //the seconde line
			{
				if(HAL_GPIO_ReadPin(GPIOA,ROW_1)==0)return 9;
				if(HAL_GPIO_ReadPin(GPIOA,ROW_2)==0)return 10;
				if(HAL_GPIO_ReadPin(GPIOA,ROW_3)==0)return 11;
				if(HAL_GPIO_ReadPin(GPIOA,ROW_4)==0)return 12;
			}
			else
			{
				wirte_line_pin_state(1,1,1,0);
				
				if(READ_ROW_1==0||READ_ROW_2==0||READ_ROW_3==0||READ_ROW_4==0) //the seconde line
				{
					if(HAL_GPIO_ReadPin(GPIOA,ROW_1)==0)return 13;
					if(HAL_GPIO_ReadPin(GPIOA,ROW_2)==0)return 14;
					if(HAL_GPIO_ReadPin(GPIOA,ROW_3)==0)return 15;
					if(HAL_GPIO_ReadPin(GPIOA,ROW_4)==0)return 16;
				}
				else return 0;
			}
		}
	}
	return 0;
}
void wirte_line_pin_state(uint8_t line_1,uint8_t line_2,uint8_t line_3,uint8_t line_4)
{
	HAL_GPIO_WritePin(GPIOA,LINE_1,line_1);
	HAL_GPIO_WritePin(GPIOA,LINE_2,line_2);
	HAL_GPIO_WritePin(GPIOA,LINE_3,line_3);
	HAL_GPIO_WritePin(GPIOA,LINE_4,line_4);
}