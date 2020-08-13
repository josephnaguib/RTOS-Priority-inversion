/*
* board.c
*
* Created: 5/20/2020 12:53:33 PM
*  Author: mnaguib
*/
#include "board.h"
void led_Init(void){
	setBit(LED_DDR,LED_PIN);
	led_Off();
}
void led_On(void){
	setBit(LED_Port,LED_PIN);
}
void led_Off(void){
	clearBit(LED_Port,LED_PIN);
}
void led_Toggle(void){
	togglebit(LED_Port,LED_PIN);
}

void BUZ_Init(void){
	setBit(BUZ_DDR,BUZ_PIN);
	BUZ_Off();
}
void BUZ_On(void){
	setBit(Buz_Port,BUZ_PIN);
}
void BUZ_Off(void){
	clearBit(Buz_Port,BUZ_PIN);
}
void BUZ_Toggle(void){
	togglebit(Buz_Port,BUZ_PIN);
}

void leds_Init(INT8U u8Leds){
	/*Leds EN*/
	setBit(LEDS_EN_DDR,LEDS_EN_PIN);
	setBit(LEDS_EN_PORT,LEDS_EN_PIN);
	/*OUT*/
	setBits(LEDS_DDR,u8Leds);
	/*OFF*/
	leds_Off(u8Leds);
}
void leds_On(INT8U u8Leds){
	setBits(LEDS_Port,u8Leds);
}
void leds_Off(INT8U u8Leds){
	clearBits(LEDS_Port,u8Leds);
}
void leds_Toggle(INT8U u8Leds){
	togglebits(LEDS_Port,u8Leds);
}

void BTN_Init(Button btn,IN_STATE state){
	clearBit(BTN_DDR,btn);
	switch(state){
		case IN_STATE_NONE:
		clearBit(BTN_Port,btn);
		break;
		case IN_STATE_PULLUP:
		setBit(BTN_Port,btn);
		break;
		default:
		break;
	}
}
Bool BTN_IsPressed(Button btn){
	return (!readBit(BTN_PIN,btn));
}
