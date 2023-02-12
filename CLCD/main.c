#include "STD_TYPES.h"
#include"CLCD_interface.h"
#include"DIO_interface.h"
void main(){
	DIO_u8SetPortDirection(DIO_u8PORTD,DIO_u8PORT_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_OUTPUT);
	CLCD_voidInit();
	u8 Local_u8Arr[]={0b00000001,0b00000011,0b00000000,0b00000001,0b00000001,0b00000001,0b00000001,0b00000001};
	CLCD_voidWriteSpecialCharacter(Local_u8Arr,0,1,8);
	while(1)
	{

	}

}

