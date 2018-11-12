/*
 * led.c
 *
 * Created: 05.04.2016 17:02:37
 *  Author: sondreab
 */ 

#include <avr/io.h>
#include "macro.h"
#include "led.h"

void led_init()
{
	DDRB |= (1<<DDB0) | (1<<DDB2) | (1<<DDB4) | (1<<DDB6);
	
	for(int i = 0; i < 4; i++)
	{
		set_bit(PORTB, i*2);
	}
	
	
}

void led_set(int n, int v)
{
	switch(n)
	{
		case 0:
		if(v)
		{
			clr_bit(PORTB, 0);
		}else
		{
			set_bit(PORTB, 0);
		}
		break;
		
		case 1:
		if(v)
		{
			clr_bit(PORTB, 2);
		}else
		{
			set_bit(PORTB, 2);
		}
		break;
		
		case 2:
		if(v)
		{
			clr_bit(PORTB, 4);
		}else
		{
			set_bit(PORTB, 4);
		}
		break;
		
		case 3:
		if(v)
		{
			clr_bit(PORTB, 6);
		}else
		{
			set_bit(PORTB, 6);
		}
		break;
	}
}