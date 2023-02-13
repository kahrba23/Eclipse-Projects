#include "STD_TYPES.h"
#include"CLCD_interface.h"
#include"DIO_interface.h"
#include <util/delay.h>
void main(){
	DIO_u8SetPortDirection(DIO_u8PORTD,DIO_u8PORT_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_OUTPUT);
	CLCD_voidInit();
	u8 Local_u8Arr[]={0b00000001,0b00000011,0b00000000,0b00000001,0b00000001,0b00000001,0b00000001,0b00000001};
	u8 Local_u8inc1=0,Local_u8inc2=3;

	while(1)
	{
		CLCD_voidGoToXY(0,Local_u8inc1);
		CLCD_voidSendString("AYAT");
		_delay_ms(2000);
		if(Local_u8inc1<12) Local_u8inc1+=6;
		else Local_u8inc1=0;
		CLCD_voidSendCommand(1);
		CLCD_voidGoToXY(1,Local_u8inc2);
		CLCD_voidSendString("AYAT");
		_delay_ms(2000);
		if(Local_u8inc2<15) Local_u8inc2+=6;
		else Local_u8inc2=3;
		CLCD_voidSendCommand(1);

	}

}
