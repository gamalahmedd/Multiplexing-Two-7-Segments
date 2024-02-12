#ifndef SEV_SEGMENT_H_
#define SEV_SEGMENT_H_
/*
	Function Name        : SEV_SEGMENT_vInit
	Function Returns     : void
	Function Arguments   : unsigned char portname
	Function Description : Set the direction of the given port 1 = output
*/
void SEV_SEGMENT_vInit(unsigned char portname);
/*
	Function Name        : SEV_SEGMENT_vWrite
	Function Returns     : void
	Function Arguments   : unsigned char portname, unsigned char number, unsigned char *type
	Function Description : write the given value to port to be showed in 7 segment screen
*/
void SEV_SEGMENT_vWrite(unsigned char portname, unsigned char number, unsigned char *type);
/*
	Function Name        : SEV_SEGMENT_vInitBCD
	Function Returns     : void
	Function Arguments   : unsigned char portname
	Function Description : Set the direction of the given port 1 = output
*/
void SEV_SEGMENT_vInitBCD(unsigned char portname);
/*
	Function Name        : SEV_SEGMENT_vWriteBCD
	Function Returns     : void
	Function Arguments   : unsigned char portname, unsigned char number, unsigned char *type
	Function Description : write the given value to port to be showed in 7 segment screen
*/
void SEV_SEGMENT_vWriteBCD(unsigned char portname, unsigned char number);
#endif