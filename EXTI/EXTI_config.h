/**************************************************/
/**************************************************/
/********* Author: Ahmed Abdallah *****************/
/*********      LAYER: MCAL       *****************/
/*********      SWC: External INT           *******/
/**************************************************/
/**************************************************/
#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_
/*Options:
     1-LOW_LEVEL
     2-ON_CHANGE
     3-FALLING_EDGE
     4-RISING_EDGE
                    */
#define INT0_SENSE   FALLING_EDGE
#define INT1_SENSE   FALLING_EDGE
/*Options:
     1-ENABLED
     2-DISABLED
                    */
#define INT0_INIT_STATE ENABLED
#define INT1_INIT_STATE ENABLED
#endif
