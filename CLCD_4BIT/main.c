#include "STD_TYPES.h"
#include"CLCD_interface.h"
#include"DIO_interface.h"
#include <util/delay.h>
#include"PORT_interface.h"
void main(){
    PORT_voidInit();
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
