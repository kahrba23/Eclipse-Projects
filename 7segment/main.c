
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include"DIO_interface.h"
#include"DIO_register.h"
#include"SSD_interface.h"
void main()
{
	SSD_t Local_Ssd1={SSD_u8CommonCathode,DIO_u8PORTD,DIO_u8PORTC,DIO_u8PIN0 };
	SSD_u8SetNumber(SSD_u8NUM7,&Local_Ssd1);


}
