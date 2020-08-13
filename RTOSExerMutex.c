/*
* interfacingproject.c
*
* Created: 5/20/2020 10:19:02 AM
*  Author: mnaguib
*/

/* include OS headers */#include "FreeRTOS.h"#include "task.h"#include "queue.h"#include "semphr.h"/* include Our Drivers */#include "board.h"#include "uart.h"/* Proto. */void T_Low(void* pvData);void T_Med(void* pvData);void T_High(void* pvData);void system_init(void);/* OS Services Decl.*/xSemaphoreHandle mxTasks;int main(void){	/* Init Pr. */	system_init();	/* OS Services Create and Init.*/	mxTasks = xSemaphoreCreateMutex();	/* Tasks Creat. */	xTaskCreate(T_Low,"T_Low",100,NULL,1,NULL);			/* Start OS or Sched. */	vTaskStartScheduler();}void T_Low(void* pvData){	while(1){		led_On();		_delay_ms(2000);		led_Toggle();		_delay_ms(2000);		xSemaphoreTake(mxTasks,portMAX_DELAY);		xTaskCreate(T_High,"T_High",100,NULL,3,NULL);		xTaskCreate(T_Med,"T_Med",100,NULL,2,NULL);		xSemaphoreGive(mxTasks);		vTaskDelay(20);	}}void T_High(void* pvData){	while(1){		led_On();		_delay_ms(500);		led_Toggle();		_delay_ms(500);		xSemaphoreTake(mxTasks,portMAX_DELAY);		while(1);	}}
void T_Med(void* pvData){	while(1){		led_On();		_delay_ms(7000);		led_Off();		vTaskDelay(50);	}}void system_init(void){		UART_Init(UART_0,9600);	led_Init();	//UART_LowStr(UART_0,"Started ...\r\n");
}
