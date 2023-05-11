/*
 * ADC_DRIVER.c
 *
 * Created: 1/30/2023 9:19:12 PM
 *  Author: Ahmed Sherif
 */ 
#include "DIO_DRIVER.h"
#include "bitwise.h"
#include <avr/io.h>
void ADC_vInt(void)
{
	SET(ADMUX,REFS0);
	SET(ADMUX,REFS1);
	SET(ADMUX,MUX4);
	SET(ADCSRA,ADEN);//Enabels adc
	SET(ADCSRA,ADPS2);
	SET(ADCSRA,ADPS1);


}

short ADC_u16Read()
{
	short return_val;
	SET(ADCSRA,ADSC);
	while(READ(ADCSRA,ADSC)==1);
	return_val=ADCL;
	return_val|=(ADCH<<8);
	return return_val;
}
