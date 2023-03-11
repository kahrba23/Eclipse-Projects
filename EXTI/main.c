#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include"DIO_interface.h"
#include "EXTI_interface.h"
#include"GIE_interface.h"
#include"PORT_interface.h"

void INT1_ISR(void);
void main(void)
{
	PORT_voidInit();
	EXTI_u8Int0SetSenseControl(FALLING_EDGE);
	EXTI_u8IntEnable(INT1);
	GIE_voidEnable();
	EXTI_u8IntSetCallBack(INT1,&INT1_ISR);
	while(1)
	{

	}
}
void INT1_ISR(void)
{
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
}

