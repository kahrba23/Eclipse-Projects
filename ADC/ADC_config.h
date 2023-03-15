/*************************************************/
/*************************************************/
/********* Author: Ahmed Abdallah ****************/
/*********      LAYER: MCAL      *****************/
/*********      SWC: ADC         ****************/
/*********      DATE: 12/3/2023  *****************/
/*************************************************/
/*************************************************/
#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_


#define V_REF                    AREF

#define LEFT_ADJUST             ADC_8_BIT

#define ADC_STATE                ADC_ENABLED

#define ADC_PRISCALER            DIVISION_FACTOR128
#define ADC_PRISCALER_MASK       0b11111000

#define ADC_ADMUX_MASK           0b11110000

#define ADC_u32TIMEOUT           50000

#endif
