#ifndef TIMER_ZERO_H_
#define TIMER_ZERO_H_
/*
	Function Name        : TIMER_ZERO_vInitNormalMode
	Function Returns     : void
	Function Arguments   : unsigned char timer_count, unsigned char interrupt_enable
	Function Description : Initialize Timer0 with normal mode
*/
void TIMER_ZERO_vInitNormalMode(unsigned char timer_count, unsigned char interrupt_enable);
/*
	Function Name        : TIMER_ZERO_vInitCTCMode
	Function Returns     : void
	Function Arguments   : unsigned char timer_count, unsigned char interrupt_enable
	Function Description : Initialize Timer0 with ctc mode
*/
void TIMER_ZERO_vInitCTCMode(unsigned char timer_count, unsigned char interrupt_enable);


#endif