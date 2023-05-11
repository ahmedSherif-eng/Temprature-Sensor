/*
 * practise.c
 *
 * Created: 2/9/2023 6:57:43 PM
 *  Author: Ahmed Sherif
 */ 


#include <avr/io.h>
#include "./HAL/LCD.h"
int main(void)
{
	LCD_vInit();
	ADC_vInt();
	LCD_vSend_string("Temprature =");
	 unsigned short temp;
	 unsigned short volt;
    while(1)
    {
		
			volt=(ADC_u16Read()*2.5);
			if(volt>1000)
			{
				temp=(volt-1000)/10;
				LCD_vSend_char(' ');
				LCD_vSend_char((temp/10)+48);
				LCD_vSend_char((temp%10)+48);
				LCD_vSend_char(0xDF);
				LCD_vMove_Cursor(1,13);
			}
			else
			{
				temp=(1000-volt)/10;
				LCD_vSend_char('-');
				LCD_vSend_char((temp/10)+48);
				LCD_vSend_char((temp%10)+48);
				LCD_vSend_char(0xDF);
				LCD_vMove_Cursor(1,13);
			}					
				
    }
}