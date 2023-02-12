/*************************************************/
/*************************************************/
/********* Author: Ahmed Abdallah ****************/
/*********      LAYER: HAl      ******************/
/*********      SWC: CLCD          ***************/
/*********      DATE: 2/11/2023    ***************/
/*************************************************/
/*************************************************/
#include"BIT_MATH.h"
#include "STD_TYPES.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include"CLCD_conig.h"
#include "CLCD_interface.h"
#include"CLCD_private.h"



void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/*Set RS pin to low for command*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);

	/*Set RW pin to low for write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/*Set command to data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);

	/*Set enable pulse */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(3);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	/*Set RS pin to high for data*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);

	/*Set RW pin to low for write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/*Set data to data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);

	/*Set enable pulse */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(3);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

}

void CLCD_voidInit(void)
{
	/*wait more than 30 ms */
	_delay_ms(40);
	/*function set command : 2 lines ,5*8 font size  */
	CLCD_voidSendCommand(0b00111000);

	/*function set command :display screen,turn off cursor,turn off blink*/
	CLCD_voidSendCommand(0b00001100);

	/*clear display*/
	CLCD_voidSendCommand(1);

}

void CLCD_voidSendString(const char* Copy_pcString)
{
	u8 Local_u8Inc=0;
	while(Copy_pcString[Local_u8Inc]!='\0')
	{
		CLCD_voidSendData(Copy_pcString[Local_u8Inc]);
		Local_u8Inc++;
	}

}

void CLCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	/*Data hold in DDRAM address register*/


	/*Hold address*/
	u8 Local_u8Address;

	/*Location at First line*/
	if(Copy_u8XPos==0)
	{
		Local_u8Address=Copy_u8YPos;
	}

	/*Location at Second line*/
	else if(Copy_u8XPos==1)
	{
		Local_u8Address=Copy_u8YPos+0x40;
	}

	/*Set bit number 7 for set DDRAM Address command then send the command(for command 0 0 )(  1 ac6 ac5 ac4 ac3 ac2 ac1 ac0 )*/
	CLCD_voidSendCommand(128+Local_u8Address);
}
void CLCD_voidWriteSpecialCharacter(u8* Copy_pu8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	/*Calculate CG RAM address each block 8 bytes*/
	u8 Local_u8CGRAMAddress=Copy_u8PatternNumber*8,Local_u8Iterator;

	/*send CG RAM address command to LCD ,setting bit 6,clear bit 7*/
	CLCD_voidSendCommand(64+Local_u8CGRAMAddress);

	/*write the pattern in CG RAM*/
	for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{
		CLCD_voidSendData(Copy_pu8Pattern[Local_u8Iterator]);
	}

	/*Go to DD RAM to Display data in CG RAM*/
	CLCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);

	/*Display data in CGRAM in screen*/
	CLCD_voidSendData(Copy_u8PatternNumber);
}
