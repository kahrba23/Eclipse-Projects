#include<avr/io.h>
#include<util/delay.h>
void main()
{
	 DDRD= 0b00000010;
	while(1)
	{
	 PORTD = 0b00000010;
	 _delay_ms(1000);
	 PORTD=0;
	 _delay_ms(1000);
	}

}
