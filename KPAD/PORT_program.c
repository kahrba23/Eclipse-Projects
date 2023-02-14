/*************************************************/
/*************************************************/
/********* Author: Ahmed Abdallah ****************/
/*********      LAYER: MCAL      ******************/
/*********      SWC: PORT         ***************/
/*********      DATE: 13/2/2023  ***************/
/*************************************************/
/*************************************************/
#include"STD_TYPES.h"
#include"PORT_config.h"
#include"PORT_private.h"
#include"PORT_interface.h"
#include"PORT_register.h"

void PORT_voidInit(void)
{
   DDRD=PORTD_DIR;
   DDRC=PORTC_DIR;
   DDRB=PORTB_DIR;
   PORTD=PORTD_INIT;
   PORTC=PORTC_INIT;
   PORTB=PORTB_INIT;
}
