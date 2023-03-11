/**************************************************/
/**************************************************/
/********* Author: Ahmed Abdallah *****************/
/*********      LAYER: MCAL       *****************/
/*********      SWC: External INT           *******/
/**************************************************/
/**************************************************/
#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

#define GICR          *((volatile u8*)0x3D)
#define GICR_INT0     0
#define GICR_INT1     1


#define GIFR          *((volatile u8*)0x3C)


#define MCUCR         *((volatile u8*)0x69)
#define MCUCR_ISC00   0
#define MCUCR_ISC01   1
#define MCUCR_ISC10   2
#define MCUCR_ISC11   3

#endif
