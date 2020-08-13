/*
* uart.h
*
* Created: 6/3/2020 2:33:49 PM
*  Author: mnaguib
*/


#ifndef UART_H_
#define UART_H_

#define  F_CPU 8000000UL
#include "avr/io.h"
#include "data_types.h"
#include "bit_math.h"
#include "util/delay.h"
#include "ext_interrrupt.h"
//#include "queue.h"


typedef enum{
	UART_0,UART_1
}UART_Type;

void UART_Init(UART_Type uartNum,INT32U u32Baud);
void UART_SendByte(UART_Type uartNum, INT8U u8Data);
void UART_SendStr(UART_Type uartNum, INT8U *pu8Data);

INT8U UART_ReceiveByte(UART_Type uartNum);
Bool UART_ReceiveByte_Unblock(UART_Type uartNum, INT8U *pu8Data);

#endif /* UART_H_ */