/**************************************************/
/**************************************************/
/*********      Author: Ahmed Abdallah ************/
/*********      LAYER: HAL           **************/
/*********      SWC: KPAD          ****************/
/**************************************************/
/**************************************************/
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "KPAD_config.h"
#include "KPAD_interface.h"
#include "KPAD_private.h"


u8 KPAD_u8GetPressedKey(void)
{
	u8 Local_PressedKey=KPAD_NO_PRESSED_KEY,Local_u8PinState;
	u8 Local_u8ColumnIndex,Local_u8RowIndex;
	static u8 Local_u8KPADArr[ROW_NUM][COLUMN_NUM]=KPAD_ARR_VAL;
	static u8 Local_u8KPADColumnArr[COLUMN_NUM]={KPAD_COLUMN0_PIN,KPAD_COLUMN1_PIN,KPAD_COLUMN2_PIN,KPAD_COLUMN3_PIN};
	static u8 Local_u8KPADRowArr[ROW_NUM]={KPAD_ROW0_PIN,KPAD_ROW1_PIN,KPAD_ROW2_PIN,KPAD_ROW3_PIN};
	for(Local_u8ColumnIndex=0;Local_u8ColumnIndex<COLUMN_NUM;Local_u8ColumnIndex++)
	{
		/*Activate Current Column*/
		DIO_u8SetPinValue(KPAD_PORT,Local_u8KPADColumnArr[Local_u8ColumnIndex],DIO_u8PIN_LOW);

		for(Local_u8RowIndex=0;Local_u8RowIndex<ROW_NUM;Local_u8RowIndex++)
		{
			/*Read the current row*/
			DIO_u8GetPinValue(KPAD_PORT,Local_u8KPADRowArr[Local_u8RowIndex],&Local_u8PinState);
			/*check switch is pressed*/
			if(DIO_u8PIN_LOW==Local_u8PinState)
			{
				Local_PressedKey=Local_u8KPADArr[Local_u8RowIndex][Local_u8ColumnIndex];
				/*Polling or busy waiting until the key is released*/
				while(DIO_u8PIN_LOW==Local_u8PinState)
				{
					DIO_u8GetPinValue(KPAD_PORT,Local_u8KPADRowArr[Local_u8RowIndex],&Local_u8PinState);
				}
				return Local_PressedKey;
			}

		}
		/*Deactivate current column*/
		DIO_u8SetPinValue(KPAD_PORT,Local_u8KPADColumnArr[Local_u8ColumnIndex],DIO_u8PIN_HIGH);
	}
	return Local_PressedKey;
}
