#include "STD_TYPES.h"
#include"CLCD_interface.h"
#include"PORT_interface.h"
#include"ADC_interface.h"
#include<util/delay.h>
#include"DIO_interface.h"
#include"GIE_interface.h"
void Func(void);
void main(){
	PORT_voidInit();
	CLCD_voidInit();
	GIE_voidEnable();
	ADC_voidInit();
	u8 Local_Reading=0;
	u16 Local_MilliVolt,Local_Temp=0;
	while(1)
	{
		ADC_u8StartConversionAsynch(0,&Local_Reading,Func);
		Local_MilliVolt=(u16)(((u32)(Local_Reading*5000UL))/(256UL));
		Local_Temp=Local_MilliVolt/10UL;
		while(Local_Temp)
		{
			u8 num=Local_Temp%10;
			Local_Temp/=10;
			CLCD_voidSendData(num+'0');
		}
		_delay_ms(2000);
		CLCD_voidSendCommand(0x01);
		_delay_ms(2000);
	}

}
void Func(void)
{
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN4,DIO_u8PIN_HIGH);
}
