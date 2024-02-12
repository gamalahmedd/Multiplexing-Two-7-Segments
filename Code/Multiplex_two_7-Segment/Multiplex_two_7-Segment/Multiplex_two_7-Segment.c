#include "SEV_SEGMENT.h"
#include "MACROS.h"
#include "TIMER_ZERO.h"
#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char counter1 = 0;
volatile unsigned char counter2 = 0;
volatile unsigned char counter3 = 0;

int main(void)
{
    SEV_SEGMENT_vInit('A');
	TIMER_ZERO_vInitCTCMode(80, 1);
	//Initialize PB0, PB1 as control pins for two 7-segment
	SET_BIT(DDRB, PIN0);
	SET_BIT(DDRB, PIN1);
	while(1)
	{
		counter3 = 0;
		CLR_BIT(PORTB, PIN0);
		SET_BIT(PORTB, PIN1);
		SEV_SEGMENT_vWrite('A', (counter1 / 10), "Cathode");
		while(counter3 == 0);
		counter3 = 0;
		SET_BIT(PORTB, PIN0);
		CLR_BIT(PORTB, PIN1);
		SEV_SEGMENT_vWrite('A', (counter1 % 10), "Cathode");
		while(counter3 == 0);
		if(counter2 >= 100)
		{
			counter1++;
			if(counter1 == 21)
			{
				counter1 = 0;
			}
			counter2 = 0;
		}
	}
}

ISR(TIMER0_COMP_vect)
{
	counter2++;
	counter3 = 1;
}