/*************************************************/
/*************************************************/
/********* Author: Ahmed Abdallah ****************/
/*********      LAYER: MCAL      ******************/
/*********      SWC: PORT         ***************/
/*********      DATE: 13/2/2023  ***************/
/*************************************************/
/*************************************************/
#ifndef PORT_CONFIG_H_
#define PORT_CONFIG_H_
/*  0 for input
    1 for output  */

#define PORTD_PIN0_DIR   1
#define PORTD_PIN1_DIR   1
#define PORTD_PIN2_DIR   1
#define PORTD_PIN3_DIR   1
#define PORTD_PIN4_DIR   1
#define PORTD_PIN5_DIR   1
#define PORTD_PIN6_DIR   1
#define PORTD_PIN7_DIR   1

#define PORTC_PIN0_DIR   1
#define PORTC_PIN1_DIR   1
#define PORTC_PIN2_DIR   1
#define PORTC_PIN3_DIR   0
#define PORTC_PIN4_DIR   0
#define PORTC_PIN5_DIR   0
#define PORTC_PIN6_DIR   0
#define PORTC_PIN7_DIR   0


#define PORTB_PIN0_DIR   0
#define PORTB_PIN1_DIR   0
#define PORTB_PIN2_DIR   0
#define PORTB_PIN3_DIR   0
#define PORTB_PIN4_DIR   0
#define PORTB_PIN5_DIR   0
#define PORTB_PIN6_DIR   0
#define PORTB_PIN7_DIR   0



/*
 * if DIR=0 so 1 for active pull up resistor 0 for floating
 * if DIR=1 so 1 for high in pin  0 for low in pin
 */

#define PORTD_PIN0_INIT  0
#define PORTD_PIN1_INIT  0
#define PORTD_PIN2_INIT  0
#define PORTD_PIN3_INIT  0
#define PORTD_PIN4_INIT  0
#define PORTD_PIN5_INIT  0
#define PORTD_PIN6_INIT  0
#define PORTD_PIN7_INIT  0

#define PORTC_PIN0_INIT  0
#define PORTC_PIN1_INIT  0
#define PORTC_PIN2_INIT  0
#define PORTC_PIN3_INIT  0
#define PORTC_PIN4_INIT  0
#define PORTC_PIN5_INIT  0
#define PORTC_PIN6_INIT  0
#define PORTC_PIN7_INIT  0


#define PORTB_PIN0_INIT  0
#define PORTB_PIN1_INIT  0
#define PORTB_PIN2_INIT  0
#define PORTB_PIN3_INIT  0
#define PORTB_PIN4_INIT  0
#define PORTB_PIN5_INIT  0
#define PORTB_PIN6_INIT  0
#define PORTB_PIN7_INIT  0



#endif
