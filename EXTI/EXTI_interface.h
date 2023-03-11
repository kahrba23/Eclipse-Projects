/**************************************************/
/**************************************************/
/********* Author: Ahmed Abdallah *****************/
/*********      LAYER: MCAL       *****************/
/*********      SWC: External INT           *******/
/**************************************************/
/**************************************************/
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define LOW_LEVEL    1
#define ON_CHANGE    2
#define FALLING_EDGE 3
#define RISING_EDGE  4
#define INT0  1
#define INT1  2
/*Description : A function to set required sense control of INT0 using (PREBUILD) configuration
 Input : Copy_u8Sense ,options are :
   1- LOW_LEVEL
   2- ON_CHANGE
   3- FALLING_EDGE
   4- RISING_EDGE
   output: Error state with type u8
                                       */
void EXTI_voidInt0Init(void);
/*Description : A function to set required sense control of INT1 using (PREBUILD) configuration
 Input : Copy_u8Sense ,options are :
   1- LOW_LEVEL
   2- ON_CHANGE
   3- FALLING_EDGE
   4- RISING_EDGE
   output: Error state with type u8
                                       */
void EXTI_voidInt1Init(void);

/*Description : A function to set required sense control of INT0 using (POSTBUILD) configuration
 Input : Copy_u8Sense ,options are :
   1- LOW_LEVEL
   2- ON_CHANGE
   3- FALLING_EDGE
   4- RISING_EDGE
   output: Error state with type u8
                                       */
u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense);
/*Description : A function to set required sense control of INT1 using (POSTBUILD) configuration
 Input : Copy_u8Sense ,options are :
   1- LOW_LEVEL
   2- ON_CHANGE
   3- FALLING_EDGE
   4- RISING_EDGE
   output: Error state with type u8
                                       */
u8 EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense);

/*Description : A function to Enable INT using (POSTBUILD) configuration
 Input : Copy_u8Int ,options are :
   1- INT0
   2- INT1
   output: Error state with type u8
                                       */
u8 EXTI_u8IntEnable(u8 Copy_u8Int);

/*Description : A function to Disable INT using (POSTBUILD) configuration
 Input : Copy_u8Int ,options are :
   1- INT0
   2- INT1
   output: Error state with type u8
                                       */
u8 EXTI_u8IntDisable(u8 Copy_u8Int);
/*Description : A function to Call ISR of Interrupt using (POSTBUILD) configuration
 Input : Copy_u8Int ,options are :
   1- INT0
   2- INT1
   Input : Copy_pvInt0Func is Pointer to function which u created in your main.c file
   output: Error state with type u8
                                       */
u8 EXTI_u8IntSetCallBack(u8 Copy_u8Int,void(*Copy_pvInt0Func)(void));

#endif
