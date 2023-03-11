/**************************************************/
/**************************************************/
/********* Author: Ahmed Abdallah *****************/
/*********      LAYER: MCAL       *****************/
/*********      SWC: GIE          *****************/
/*********      DATE: 6/3/2023    *****************/
/**************************************************/
/**************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_interface.h"
#include "GIE_register.h"
 void GIE_voidEnable(void)
 {
	 SET_BIT(SREG,SREG_I);
 }
 void GIE_voidDisable(void)
 {
	 CLR_BIT(SREG,SREG_I);
 }
