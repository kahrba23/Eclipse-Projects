/**************************************************/
/**************************************************/
/*********      Author: Ahmed Abdallah ************/
/*********      LAYER: HAL           **************/
/*********      SWC: KPAD          ****************/
/**************************************************/
/**************************************************/
#ifndef KPAD_CONFIG_H_
#define KPAD_CONFIG_H_

#define KPAD_PORT                DIO_u8PORTD
#define KPAD_NO_PRESSED_KEY      0xff


#define KPAD_COLUMN0_PIN     DIO_u8PIN0
#define KPAD_COLUMN1_PIN     DIO_u8PIN1
#define KPAD_COLUMN2_PIN     DIO_u8PIN2
#define KPAD_COLUMN3_PIN     DIO_u8PIN3

#define KPAD_ROW0_PIN        DIO_u8PIN4
#define KPAD_ROW1_PIN        DIO_u8PIN5
#define KPAD_ROW2_PIN        DIO_u8PIN6
#define KPAD_ROW3_PIN        DIO_u8PIN7



#define KPAD_ARR_VAL             {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}

#endif
