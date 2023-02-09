#include<avr/io.h>
#include<util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
void main()
{
	u8 SEVEN_S[10]={0b0111111,0b0000110,0b1011011,0b1001111,0b1100110,0b1101101,0b1111101,0b0000111,0b1111111,0b1100111};
	DDRD=0xff;
	SET_BIT(PORTD,3);










}
