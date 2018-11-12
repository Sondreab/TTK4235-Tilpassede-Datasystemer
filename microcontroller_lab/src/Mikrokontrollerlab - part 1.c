/*
 * Mikrokontrollerlab___part_1.c
 *
 * Created: 05.04.2016 16:33:29
 *  Author: sondreab
 */ 


#include <avr/io.h>
#include <stdio.h>
#include "macro.h"
#include "switch.h"
#include "led.h"
#include "usart.h"
#include "adc.h"
#include "pwm.h"

int main(void)
{
	usart_init();
	adc_init();
	pwm_init();
	
	

	while(1)
	{
		int X = adc_read('X');
		//int Y = adc_read('Y');
		
		double u = (X/1048.0)*1.2;
		
		pwm_set_width(0.9 + u);
	}
}
