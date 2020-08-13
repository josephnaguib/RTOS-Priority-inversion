/*
* board.h
*
* Created: 5/20/2020 12:53:20 PM
*  Author: mnaguib
*/


#ifndef BOARD_H_
#define BOARD_H_

/*
Single led :PB4
8-Leds     :PA0-7 -> Enable latch PF1(Active High)
Buttons    :PD0-1->(Active Low)
Buuzer     :PE7 ->(Active High)
*/
#define  F_CPU 8000000UL
#include "avr/io.h"
#include "data_types.h"
#include "bit_math.h"
#include "util/delay.h"
//#define PORTA_R (*((volatile INTU8*)(0x3B)))
#define Buz_Port PORTE
#define BUZ_DDR  DDRE
#define BUZ_PIN  PE7

#define LED_Port PORTB
#define LED_DDR  DDRB
#define LED_PIN  PB4

#define BTN_Port PORTD
#define BTN_DDR  DDRD
#define BTN_PIN  PIND

typedef enum{
	BTN0,BTN1
}Button;

typedef enum{
	IN_STATE_NONE,IN_STATE_PULLUP
}IN_STATE;

#define LEDS_Port		PORTA
#define LEDS_DDR		DDRA
/*LEDS Enable*/
#define LEDS_EN_PORT	PORTF
#define LEDS_EN_DDR		PORTF
#define LEDS_EN_PIN		PF1

void led_Init(void);
void led_On(void);
void led_Off(void);
void led_Toggle(void);

void BUZ_Init(void);
void BUZ_On(void);
void BUZ_Off(void);
void BUZ_Toggle(void);

void leds_Init(INT8U u8Leds);
void leds_On(INT8U u8Leds);
void leds_Off(INT8U u8Leds);
void leds_Toggle(INT8U u8Leds);

void BTN_Init(Button btn,IN_STATE stat);
Bool BTN_IsPressed(Button btn);


#endif /* BOARD_H_ */