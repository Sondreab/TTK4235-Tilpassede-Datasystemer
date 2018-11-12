/*
 * adc.c
 *
 * Created: 05.04.2016 19:03:38
 *  Author: sondreab
 */ 

#include <avr/io.h>
#include "macro.h"
#include "adc.h"

int adc_init()
{
	ADCSRA = (1 << ADEN);
	ADCSRA |= (1 << ADPS2)
			| (1 << ADPS1)
			| (1 << ADPS0); //Prescale med en faktor paa 1/128 -> 16MHz /128 = 125 kHz
			
	return 1;
}

int adc_read(unsigned char n)
{	
	if((n == 'x') | (n == 'X'))
	{
		ADMUX = (1 << MUX0);
	}else if((n == 'y') | (n == 'Y')){
		ADMUX &= ~(1 << MUX0);
	}
	
	ADCSRA |= (1 << ADSC);
	
	while(test_bit(ADCSRA, ADSC));
	
	return ADCW;
}