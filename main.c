#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
int main(void) 
{   
    //ENTRADAS 
	DDRB &= ~(1<<1);
	DDRB &= ~(1<<2);
	
    PORTB |= (1<<1);
    PORTB |= (1<<2);
    
	// SAÍDAS
	DDRB |= (1<<3);
	DDRB |= (1<<4); 
	DDRB |= (1<<5);
	
	PORTB &= ~(1<<3);
	PORTB &= ~(1<<4);
	PORTB &= ~(1<<5);
	
	int estado = 0;
	int tempo = 0;
	while (1)
    {
		if (estado == 0)
		{
			PORTB &= ~(1<<3);
			PORTB &= ~(1<<4);
			PORTB &= ~(1<<5);
			
			if (!( PINB & (2<<1)))
			{
				estado = 1;
			}
		}
		if (estado ==1)
		{
			PORTB |= (1<<3);
			PORTB |= (1<<4);
			tempo = 5000;
			estado = 2;
		}
		if (estado == 2)
		{
			--tempo;
			_delay_ms(1);
			if (tempo == 0)
			{
				estado = 3;
			}
		}
		if (estado == 3)
		{
			PORTB &= ~(1<<4);
			PORTB |= (1<<5);
			estado = 4;
		}
		if (estado == 4)
		{
			if (!( PINB & (1<<1)))
			{
				estado = 0;
			}
		}
		if ((!( PINB & (1<<1)))&& (estado ==2))
		{
			estado = 0;
		}
		
    }
}
