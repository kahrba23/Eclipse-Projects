#include "STD_TYPES.h"
#include"CLCD_interface.h"
#include "KPAD_interface.h"
#include"PORT_interface.h"
void main(){
	u8 Local_u8Key;
    PORT_voidInit();
    CLCD_voidInit();
    while(1)
    {
    do {Local_u8Key=KPAD_u8GetPressedKey();}
    while(Local_u8Key==0xff);
    	CLCD_voidSendData(Local_u8Key+'0');
    }

}
