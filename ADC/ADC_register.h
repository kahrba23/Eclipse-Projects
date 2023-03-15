/*************************************************/
/*************************************************/
/********* Author: Ahmed Abdallah ****************/
/*********      LAYER: MCAL      *****************/
/*********      SWC: ADC         ****************/
/*********      DATE: 12/3/2023  *****************/
/*************************************************/
/*************************************************/

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define ADMUX             *((volatile u8*)0x7C)   //ADC multiplexer selsection register
#define ADMUX_REFS1       7                       //Reference selection bit 1
#define ADMUX_REFS0       6                       //Reference selection bit 1
#define ADMUX_ADLAR       5                       //ADC left adjust result


#define ADCSRA            *((volatile u8*)0x7A)   //ADC control and status register
#define ADCSRA_ADEN       7                       //ADC enable
#define ADCSRA_ADSC       6                       //ADC start conversion
#define ADCSRA_ADATE      5                       //ADC auto trigger enable
#define ADCSRA_ADIF       4                       //ADC interrupt flag
#define ADCSRA_ADIE       3                       //ADC interrupt enable
#define ADCSRA_ADPS2      2                       //Prescaler bit2
#define ADCSRA_ADPS1      1                       //Prescaler bit1
#define ADCSRA_ADPS0      0                       //Prescaler bit0


#define ADCH              *((volatile u8*)0x79)   //ADC high register
#define ADCL              *((volatile u8*)0x78)   //ADC low register


#endif
