/*
 * pwm.c
 *
 * Created: 12.04.2016 18:18:00
 *  Author: sondreab
 */ 

#include "macro.h"
#include "pwm.h"

void pwm_init()
{
	DDRB |= (1<<DDB5);
	
	// fast pwm
	TCCR1A |= (1 << COM1A1);
	TCCR1A &= ~(1 << COM1A0);
	
	//set fast PWM, top ICR1
	TCCR1B |= (1 << WGM13) | (1 << WGM12);
	TCCR1A |= (1 << WGM11);
	
	
	// 1/8 clock
	TCCR1B |= (1 << CS11);
	
	
	ICR1 = 40000;
}

void pwm_set_width(float ms)
{
	int bitfreq = (ms/20)*40000;
	if(bitfreq < 1800){
		OCR1A = 1800;
	}else if(bitfreq > 4200){
		OCR1A = 4200;
	}else{
		OCR1A = bitfreq;
	}
}