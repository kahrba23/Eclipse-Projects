/**************************************************/
/**************************************************/
/*********      Author: Ahmed Abdallah ************/
/*********      LAYER: MCAL       *****************/
/*********      SWC: DIO           ****************/
/**************************************************/
/**************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include"DIO_interface.h"
#include"DIO_register.h"
#include"SSD_interface.h"
u8 DIO_u8SetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Direction )
{
	u8 Local_u8ErrorState=0;
	if(Copy_u8Pin<=DIO_u8PIN7)
	{
		if(Copy_u8Direction==DIO_u8PIN_INPUT)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTD : CLR_BIT(DDRD,Copy_u8Pin);break;
			case DIO_u8PORTC : CLR_BIT(DDRC,Copy_u8Pin);break;
			case DIO_u8PORTB : CLR_BIT(DDRB,Copy_u8Pin);break;
			default : Local_u8ErrorState=1;break;
			}
		}
		else if(Copy_u8Direction==DIO_u8PIN_OUTPUT)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTD : SET_BIT(DDRD,Copy_u8Pin);break;
			case DIO_u8PORTC : SET_BIT(DDRC,Copy_u8Pin);break;
			case DIO_u8PORTB : SET_BIT(DDRB,Copy_u8Pin);break;
			default : Local_u8ErrorState=1;break;
			}
		}
		else
		{
			Local_u8ErrorState=1;
		}
	}
	else
	{
		Local_u8ErrorState=1;
	}

	return Local_u8ErrorState;

}

u8 DIO_u8SetPortDirection(u8 Copy_u8Port,u8 Copy_u8Direction )
{

	u8 Local_u8ErrorState=0;
	switch(Copy_u8Port)
	{
	case DIO_u8PORTD :DDRD=Copy_u8Direction ;break;
	case DIO_u8PORTC :DDRC=Copy_u8Direction ;break;
	case DIO_u8PORTB :DDRB=Copy_u8Direction ;break;
	default : Local_u8ErrorState=1;break;
	}
	return Local_u8ErrorState;
}

u8 DIO_u8SetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value)
{
	u8 Local_u8ErrorState=0;
	if(Copy_u8Pin<=DIO_u8PIN7)
	{
		if(Copy_u8Value==DIO_u8PIN_LOW)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTD : CLR_BIT(PORTD,Copy_u8Pin);break;
			case DIO_u8PORTC : CLR_BIT(PORTC,Copy_u8Pin);break;
			case DIO_u8PORTB : CLR_BIT(PORTB,Copy_u8Pin);break;
			default : Local_u8ErrorState=1;break;
			}
		}
		else if(Copy_u8Value==DIO_u8PIN_HIGH)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTD : SET_BIT(PORTD,Copy_u8Pin);break;
			case DIO_u8PORTC : SET_BIT(PORTC,Copy_u8Pin);break;
			case DIO_u8PORTB : SET_BIT(PORTB,Copy_u8Pin);break;
			default : Local_u8ErrorState=1;break;
			}
		}
		else
		{
			Local_u8ErrorState=1;
		}
	}
	else
	{
		Local_u8ErrorState=1;
	}

	return Local_u8ErrorState;

}



u8 DIO_u8SetPortValue(u8 Copy_u8Port,u8 Copy_u8Value)
{

	u8 Local_u8ErrorState=0;
	switch(Copy_u8Port)
	{
	case DIO_u8PORTD :PORTD=Copy_u8Value ;break;
	case DIO_u8PORTC :PORTC=Copy_u8Value ;break;
	case DIO_u8PORTB :PORTB=Copy_u8Value ;break;
	default : Local_u8ErrorState=1;break;
	}
	return Local_u8ErrorState;

}



u8 DIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8* Copy_pu8Value)
{

	u8 Local_u8ErrorState=0;
	if(Copy_pu8Value!=NULL&&Copy_u8Pin<=DIO_u8PIN7)
	{

		switch(Copy_u8Port)
		{
		case DIO_u8PORTD :*Copy_pu8Value=GET_BIT(PIND,Copy_u8Pin);break;
		case DIO_u8PORTC :*Copy_pu8Value=GET_BIT(PINC,Copy_u8Pin);break;
		case DIO_u8PORTB :*Copy_pu8Value=GET_BIT(PINB,Copy_u8Pin);break;
		default : Local_u8ErrorState=1;break;
		}
	}
	else
	{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}
u8 SSD_u8SetNumber(u8 Copy_u8Number, SSD_t*SSD)
{
	u8 Local_u8ErrorState=0;
	if(SSD->com_type==SSD_u8CommonCathode)
	{
		DIO_u8SetPortDirection(SSD->port,DIO_u8PORT_OUTPUT);
		DIO_u8SetPinDirection(SSD->enable_port,SSD->enable_pin,DIO_u8PIN_OUTPUT);
		DIO_u8SetPinValue(SSD->enable_port,SSD->enable_pin,DIO_u8PIN_LOW);
		DIO_u8SetPortValue(SSD->port,Copy_u8Number);
	}
	else if(SSD->com_type==SSD_u8CommonAnode)
	{
		DIO_u8SetPortDirection(SSD->port,DIO_u8PORT_OUTPUT);
		DIO_u8SetPinDirection(SSD->enable_port,SSD->enable_pin,DIO_u8PIN_OUTPUT);
		DIO_u8SetPinValue(SSD->enable_port,SSD->enable_pin,DIO_u8PIN_HIGH);
		DIO_u8SetPortValue(SSD->port,~(Copy_u8Number));
	}
	else
	{
		 Local_u8ErrorState=1;
	}

	return Local_u8ErrorState;

}
