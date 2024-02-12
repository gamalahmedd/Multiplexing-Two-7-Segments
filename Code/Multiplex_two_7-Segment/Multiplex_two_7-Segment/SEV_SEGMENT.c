#include "DIO.h"
#include "MACROS.h"
#include <string.h>

void SEV_SEGMENT_vInit(unsigned char portname)
{
	DIO_vSetPortDirection(portname, 0xFF);
}

void SEV_SEGMENT_vWrite(unsigned char portname, unsigned char number, unsigned char *type)
{
	if(strcmp("Cathode", type) == 0)
	{
		unsigned char arr[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x47, 0x7f, 0x6f};
		DIO_vWritePort(portname, arr[number]);
	}
	else if(strcmp("Anode", type) == 0)
	{
		unsigned char arr[10] = {~0x3f, ~0x06, ~0x5b, ~0x4f, ~0x66, ~0x6d, ~0x7d, ~0x47, ~0x7f, ~0x6f};
		DIO_vWritePort(portname, arr[number]);
	}
	else
	{
		
	}
}

void SEV_SEGMENT_vInitBCD(unsigned char portname)
{
	DIO_vsetPinDir(portname, PIN0, OUTPUT);
	DIO_vsetPinDir(portname, PIN1, OUTPUT);
	DIO_vsetPinDir(portname, PIN2, OUTPUT);
	DIO_vsetPinDir(portname, PIN3, OUTPUT);
}

void SEV_SEGMENT_vWriteBCD(unsigned char portname, unsigned char number)
{
	DIO_vWriteLowNibble(portname, number);
}