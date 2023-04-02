#include "esp8266.h"
#include "usart.h"
#include "string.h"

//void esp8266_init(void)
//{
//	printf("AT\r\n");		//第一步		AT
//	HAL_Delay(2000);			//延迟
//	
//	printf("AT+CWJAP=\"SNB-Guest\",\"Snb28292700\"\r\n");		//第四步 wifi热点
//	HAL_Delay(5000);					//延迟
//	HAL_Delay(5000);					//延迟
//	HAL_Delay(5000);					//延迟	
//	HAL_Delay(5000);					//延迟
//	
//	printf("AT+CIPSNTPCFG=1,8,\"ntp1.aliyun.com\"\r\n");		//第三步
//	HAL_Delay(3000);					//延迟

//	printf("AT+MQTTUSERCFG=0,1,\"NULL\",\"esp8266&a1uQRc62cTT\",\"b49f894b85f40a2cd1cb806d484ceecc9c1ae8714538be3a7079f31c3c10e08c\",0,0,\"\"\r\n");		//第五步
//	HAL_Delay(3000);					//延迟			

//	printf("AT+MQTTCLIENTID=0,\"a1uQRc62cTT.esp8266|securemode=2\\,signmethod=hmacsha256\\,timestamp=1677418920869|\"\r\n");		//第六步
//	HAL_Delay(3000);					//延迟	
//	
//	printf("AT+MQTTCONN=0,\"a1uQRc62cTT.iot-as-mqtt.cn-shanghai.aliyuncs.com\",1883,1\r\n");		//第七步
//	HAL_Delay(3000);					//延迟
//}

void esp8266_init(void)
{
	char str[256];
	int len;
	
	
	strcmp(str,"AT\r\n");
	len = strlen(str);
	HAL_UART_Transmit(&huart1,(uint8_t *)str,len,0xffff);
	
	strcmp(str,"AT+CWJAP=\"SNB-Guest\",\"Snb28292700\"\r\n");
	len = strlen(str);
	HAL_UART_Transmit(&huart1,(uint8_t *)str,len,0xffff);
	
	strcmp(str,"AT+CIPSNTPCFG=1,8,\"ntp1.aliyun.com\"\r\n");
	len = strlen(str);
	HAL_UART_Transmit(&huart1,(uint8_t *)str,len,0xffff);
	
	strcmp(str,"AT+MQTTUSERCFG=0,1,\"NULL\",\"esp8266&a1uQRc62cTT\",\"b49f894b85f40a2cd1cb806d484ceecc9c1ae8714538be3a7079f31c3c10e08c\",0,0,\"\"\r\n");
	len = strlen(str);
	HAL_UART_Transmit(&huart1,(uint8_t *)str,len,0xffff);
	
	strcmp(str,"AT+MQTTCLIENTID=0,\"a1uQRc62cTT.esp8266|securemode=2\\,signmethod=hmacsha256\\,timestamp=1677418920869|\"\r\n");
	len = strlen(str);
	HAL_UART_Transmit(&huart1,(uint8_t *)str,len,0xffff);
	
	strcmp(str,"AT+MQTTCONN=0,\"a1uQRc62cTT.iot-as-mqtt.cn-shanghai.aliyuncs.com\",1883,1\r\n");
	len = strlen(str);
	HAL_UART_Transmit(&huart1,(uint8_t *)str,len,0xffff);
}
