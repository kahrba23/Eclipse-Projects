/*************************************************/
/*************************************************/
/********* Author: Ahmed Abdallah ****************/
/*********      LAYER: MCAL      *****************/
/*********      SWC: ADC         ****************/
/*********      DATE: 12/3/2023  *****************/
/*************************************************/
/*************************************************/
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC0   0
#define ADC1   1
#define ADC2   2
#define ADC3   3
#define ADC4   4
#define ADC5   5
#define ADC6   6
#define ADC7   7
#define VBG    14
#define GND    15

void ADC_voidInit(void);

u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel,u8 *Copy_pu8Reading);
u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel,u8 *Copy_pu8Reading,void(*Copy_pvNotificationFunc)(void));
#endif
