#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
int main(void) 
{   
    //ENTRADAS 
	DDRB &= ~(1<<0);
	DDRB &= ~(1<<1);
	
    PORTB |= (1<<0);
    PORTB |= (1<<1);
    
	// SAÍDAS
	DDRD |= (1<<5);
	DDRD |= (1<<6); 
	DDRD |= (1<<7);
	
	PORTD &= ~(1<<5);
	PORTD &= ~(1<<6);
	PORTD &= ~(1<<7);
	
	int estado = 0;
	int tempo = 0;
	while (1)
    {
		if (estado == 0)
		{
			PORTD &= ~(1<<5);
			PORTD &= ~(1<<6);
			PORTD &= ~(1<<7);
			
			if (!( PINB & (1<<0)))
			{
				estado = 1;
			}
		}
		if (estado ==1)
		{
			PORTD |= (1<<5);
			PORTD |= (1<<6);
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
			PORTD &= ~(1<<6);
			PORTD |= (1<<7);
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
