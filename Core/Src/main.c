/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "oled.h"
#include "oledfont.h"
#include "esp8266.h"
#include "sys.h"
#include "keyboard.h"
#include "string.h"
#include "stdlib.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define boxNumber 20
#define numberLength 11
#define passwordLength 6
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
struct user
{
	uint8_t user_number[11];
	uint8_t user_password[6];
};
struct user userId[boxNumber] = {0};

uint16_t userId_size = 0;
uint16_t input_size;
uint16_t string_num_size = 0;
uint16_t string_password_size = 0;
uint16_t user_size = 0;

uint8_t input[11];
uint8_t string_num[11];
uint8_t string_password[6];
uint8_t tx_buffer_number[11];
uint8_t tx_buffer_password[6];

uint8_t make_sure; 
uint8_t show_mode;
uint16_t keyboard_num;

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void take_goods(void);
void access_goods(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_USART1_UART_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */
	OLED_Init();
	OLED_Clear(); 
	esp8266_init();
//sprintf((char *)userId[0].user_number,"12345678901");
//	sprintf((char *)userId[0].user_password,"654321");
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

//		printf("AT+MQTTPUB=0,\"/sys/a1uQRc62cTT/esp8266/thing/event/property/post\",\"{\\\"method\\\":\\\"thing.service.property.set\\\"\\,\\\"id\\\":\\\"1698739911\\\"\\,\\\"params\\\":{\\\"number\\\":\\\"%s\\\"}\\,\\\"version\\\":\\\"1.0.0\\\"}\",1,0\r\n",tx_buffer_number);
//		HAL_Delay(1000);
//		printf("AT+MQTTPUB=0,\"/sys/a1uQRc62cTT/esp8266/thing/event/property/post\",\"{\\\"method\\\":\\\"thing.service.property.set\\\"\\,\\\"id\\\":\\\"1698739911\\\"\\,\\\"params\\\":{\\\"password\\\":\\\"%s\\\"}\\,\\\"version\\\":\\\"1.0.0\\\"}\",1,0\r\n",tx_buffer_password);
//    switch_keyboard(scale_keyboard());
		//oled_show_num();
	
		keyboard_num = scale_keyboard();
		
		switch (keyboard_num)
		{
			case 4:input[input_size] = '0',input_size+=1;break;
			
			case 1:input[input_size] = '1',input_size+=1;break;
			case 2:input[input_size] = '2',input_size+=1;break;
			case 3:input[input_size] = '3',input_size+=1;break;
			
			case 5:input[input_size] = '4',input_size+=1;break;
			case 6:input[input_size] = '5',input_size+=1;break;
			case 7:input[input_size] = '6',input_size+=1;break;
			
			case 9:input[input_size] = '7',input_size+=1;break;
			case 10:input[input_size] = '8',input_size+=1;break;
			case 11:input[input_size] = '9',input_size+=1;break;
			
			case 8:input_size-=1;break;
			case 12:input_size = 0,OLED_Clear(),memset(input,0,11),input_size = 0;;break;
			
			case 13:OLED_Clear(),sysMode = 1,show_mode = 1,input_size = 0;break;
			case 14:OLED_Clear(),sysMode = 2,show_mode = 2,input_size = 0;break;
			case 15:make_sure = 1 , input_size = 0;break;
			case 16:sysMode=0;;break;
			default:;
		}
		
		switch(show_mode)
		{
			case 0:oled_shou_welcome();break;
			case 1:oled_show_num();break;
			case 2:oled_show_get();break;
			case 3:;break;
			default:;
		}
		
		if(input_size >11)input_size = 0;
		
		OLED_ShowString(0,3,input,11);
		
		take_goods();
		access_goods();
	
	  HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
		HAL_Delay(200);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void access_goods(void)
{
	if((sysMode == 1) && (make_sure == 1))
	{
		strcpy((char *)string_num,(char *)input);
		
		for(uint8_t t = 0;t < 6;t++)
		{
			char str[]="0123456789";
			userId[0].user_password[t]=str[rand()%strlen(str)];
		}
		
		strcpy((char *)tx_buffer_password,(char *)userId[0].user_password);
		
		printf("AT+MQTTPUB=0,\"/sys/a1uQRc62cTT/esp8266/thing/event/property/post\",\"{\\\"method\\\":\\\"thing.service.property.set\\\"\\,\\\"id\\\":\\\"1698739911\\\"\\,\\\"params\\\":{\\\"password\\\":\\\"%s\\\"}\\,\\\"version\\\":\\\"1.0.0\\\"}\",1,0\r\n",tx_buffer_password);
		HAL_Delay(200);
		
		OLED_Clear();
		OLED_ShowCHinese(8,0,21);
		OLED_ShowCHinese(40,0,22);
		
		userId_size++;
		sysMode = 0;
		make_sure = 0;
	}
}

void take_goods(void)
{
	if((sysMode == 2) && (make_sure == 1))
	{
		strcpy((char *)string_password,(char *)input);
		
		if(strcmp((char *)string_password,(char *)userId[0].user_password)==0)
		{
			OLED_Clear();
			OLED_ShowCHinese(8,0,17);
			OLED_ShowCHinese(40,0,18);

		}
		else 
		{
			memset(input,0,11);
			
			OLED_Clear();
			OLED_ShowCHinese(8,0,19);
			OLED_ShowCHinese(40,0,20);
		}
		make_sure = 0;
		userId_size++;
	}
}

uint8_t check_user(void)
{
	
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
