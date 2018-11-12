/*
 * switch.c
 *
 * Created: 05.04.2016 17:02:18
 *  Author: sondreab
 */ 

#include <avr/io.h>
#include "macro.h"
#include "switch.h"

void switch_init()
{
	DDRB &= ~(1<<DDB1);
	DDRB &= ~(1<<DDB3);
	DDRB &= ~(1<<DDB5);
	DDRB &= ~(1<<DDB7);
	
	for(int i = 0; i < 4; i++)
	{
		set_bit(PORTB, (2*i)+1);
	}
}

int switch_read(int n)
{
	if(PINB & 1 << (n*2 +1))
	{
		return 0;
	}else
	{
		return 1;
	}
}
