/*
 * macro.h
 *
 * Created: 05.04.2016 17:19:33
 *  Author: sondreab
 */ 

#include <avr/io.h>

#ifndef MACRO_H_
#define MACRO_H_

#define  set_bit(reg, bit) \
	(reg |= (1 << (bit)))

#define clr_bit(reg, bit) \
	(reg &= ~(1 << (bit)))
	
#define test_bit(reg, bit) \
	(reg & (1 << (bit)))


#endif /* MACRO_H_ */