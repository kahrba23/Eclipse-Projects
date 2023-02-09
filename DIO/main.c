#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include"DIO_interface.h"


void main(void)
{
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_HIGH);
	while(1){

	}
}

