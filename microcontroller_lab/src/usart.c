/*
 * usart.c
 *
 * Created: 05.04.2016 18:09:13
 *  Author: sondreab
 */ 

#define F_CPU 16000000;

#include <avr/io.h>
#include <stdio.h>
#include "usart.h"


static FILE usart_stdout = FDEV_SETUP_STREAM(usart_putchar, NULL, _FDEV_SETUP_WRITE);

int usart_init()
{
	UBRR1 = 51;
	
	UCSR1B = (1<<RXEN1) | (1<<TXEN1);
	UCSR1C = (1<<USBS1) | (3<<UCSZ10);
	
	stdout = &usart_stdout;
	return 1;
}

int usart_putchar(int c)
{
	while (!(UCSR1A & (1<<UDRE1)) );
	
	UDR1 = c;
	
	return 1;
}