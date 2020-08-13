/*
* uart.c
*
* Created: 6/3/2020 2:34:00 PM
*  Author: mnaguib
*/
#include "uart.h"


/*volatile Queue UART0_Data;
CreateQueue(&UART0_Data);
volatile Queue UART1_Data;
CreateQueue(&UART1_Data);*/

void UART_Init(UART_Type uartNum,INT32U u32Baud){
	INT16U ubrr=0;
	ubrr=51;
	//ubrr=((8000000UL)/(16*u32Baud))-1;
	switch(uartNum){
		case UART_0:
		/* Set baud rate */
		UBRR0H = (INT8U)(ubrr>>8);
		UBRR0L = (INT8U)ubrr;
		/* Enable receiver and transmitter */
		UCSR0B = (1<<RXEN)|(1<<TXEN);
		/* Set frame format: 8data, 2stop bit */
		UCSR0C = (3<<UCSZ0);
		break;
		case UART_1:
		/* Set baud rate */
		UBRR1H = (INT8U)(ubrr>>8);
		UBRR1L = (INT8U)ubrr;
		/* Enable receiver and transmitter */
		UCSR1B = (1<<RXEN)|(1<<TXEN);
		/* Set frame format: 8data, 2stop bit */
		UCSR1C = (3<<UCSZ0);
		break;
		
	}
}

void UART_SendByte(UART_Type uartNum, INT8U u8Data){
	switch(uartNum){
		case UART_0:
		/* Wait for empty transmit buffer */
		while ( !( UCSR0A & (1<<UDRE)) )
		;
		/* Put data into buffer, sends the data */
		UDR0 = u8Data;
		break;
		case UART_1:
		/* Wait for empty transmit buffer */
		while ( !( UCSR1A & (1<<UDRE)) )
		;
		/* Put data into buffer, sends the data */
		UDR1 = u8Data;
		break;
	}
}
void UART_SendStr(UART_Type uartNum, INT8U *pu8Data){
	int i;
	for(i=0;pu8Data[i]!='\0';i++){
		UART_SendByte(uartNum,pu8Data[i]);
	}
}

INT8U UART_ReceiveByte(UART_Type uartNum){
	INT8U u8Data	=0;
	switch(uartNum){
		case UART_0:
		/* Wait for empty transmit buffer */
		while ( !(UCSR0A & (1<<RXC0)) )
		;
		/* Put data into buffer, sends the data */
		u8Data=UDR0;
		break;
		case UART_1:
		/* Wait for empty transmit buffer */
		while ( !(UCSR1A & (1<<RXC0)) )
		;
		/* Put data into buffer, sends the data */
		u8Data=UDR1;
		break;
	}
	return u8Data;
}

Bool UART_ReceiveByte_Unblock(UART_Type uartNum, INT8U *pu8Data){
	Bool result=FALSE;
	switch(uartNum){
		case UART_0:
		if((UCSR0A & (1<<RXC0)) ){
			result=TRUE;
			(*pu8Data)=UDR0;
		}
		break;
		case UART_1:
		if((UCSR1A & (1<<RXC1)) ){
			result=TRUE;
			(*pu8Data)=UDR1;
		}
	}
	return result;
}

/*ISR(USART0_RX_vect_num){
	while ( !(UCSR0A & (1<<RXC0)) )
	;
	/* Put data into buffer, sends the data */
	/*append (UDR0,&UART0_Data);
}
ISR(USART1_RX_vect_num){
	while ( !(UCSR1A & (1<<RXC1)) )
	;
	/* Put data into buffer, sends the data */
	/*append (UDR1,&UART1_Data);
}*/
