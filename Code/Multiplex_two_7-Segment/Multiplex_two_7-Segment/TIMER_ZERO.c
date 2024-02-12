#include <avr/io.h>
#include <avr/interrupt.h>
#include "MACROS.h"

void TIMER_ZERO_vInitNormalMode(unsigned char timer_count, unsigned char interrupt_enable)
{
	if(interrupt_enable == 1)
	{
		//Init timer0 with prescaler Fmc/1024
		SET_BIT(TCCR0, CS00);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
		//Set Normal Mode
		CLR_BIT(TCCR0, WGM00);
		CLR_BIT(TCCR0, WGM01);
		//Init TCNT0 with timer_count
		TCNT0 = 256 - timer_count;
		//Set Global Interrupt bit
		sei();
		//Enable Overflow Interrupt Mode
		SET_BIT(TIMSK, TOIE0);
	}
	else
	{
		//Init timer0 with prescaler Fmc/1024
		SET_BIT(TCCR0, CS00);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
		//Set Normal Mode
		CLR_BIT(TCCR0, WGM00);
		CLR_BIT(TCCR0, WGM01);
		//Init TCNT0 with timer_count
		TCNT0 = 256 - timer_count;
	}
}


void TIMER_ZERO_vInitCTCMode(unsigned char timer_count, unsigned char interrupt_enable)
{
	if(interrupt_enable == 1)
	{
		//Init timer0 with prescaler Fmc/1024
		SET_BIT(TCCR0, CS00);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
		//Set CTC Mode
		CLR_BIT(TCCR0, WGM00);
		SET_BIT(TCCR0, WGM01);
		//Init TCNT0 with 0 value
		TCNT0 = 0;
		//Init OCR0 with timer_count
		OCR0 = timer_count;
		//Set Global Interrupt bit
		sei();
		//Enable Overflow Interrupt Mode
		SET_BIT(TIMSK, OCIE0);
	}
	else
	{
		//Init timer0 with prescaler Fmc/1024
		SET_BIT(TCCR0, CS00);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
		//Set CTC Mode
		CLR_BIT(TCCR0, WGM00);
		SET_BIT(TCCR0, WGM01);
		//Init TCNT0 with 0 value
		TCNT0 = 0;
		//Init OCR0 with timer_count
		OCR0 = timer_count;
	}
}