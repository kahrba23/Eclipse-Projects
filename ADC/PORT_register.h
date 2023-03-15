/*************************************************/
/*************************************************/
/********* Author: Ahmed Abdallah ****************/
/*********      LAYER: MCAL      ******************/
/*********      SWC: PORT         ***************/
/*********      DATE: 13/2/2023  ***************/
/*************************************************/
/*************************************************/
#ifndef PORT_REGISTER_H_
#define PORT_REGISTER_H_

#define DDRD        *((volatile u8*)0x2A)
#define DDRC        *((volatile u8*)0x27)
#define DDRB        *((volatile u8*)0x24)
#define PORTD       *((volatile u8*)0x2B)
#define PORTC       *((volatile u8*)0x28)
#define PORTB       *((volatile u8*)0x25)


#endif
