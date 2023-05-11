#include "../MCAL/bitwise.h"
#include "../MCAL/DIO_DRIVER.h"
#define F_CPU 8000000UL
#include "util/delay.h"
#include "../HAL/LCD.h"
void LCD_vInit()
{	_delay_ms(200);
	#if defined eight_bit_mode
	DIO_SET_PIN_DIRECTION(PORT,0,1);
	DIO_SET_PIN_DIRECTION(PORT,1,1);
	DIO_SET_PIN_DIRECTION(PORT,2,1);
	DIO_SET_PIN_DIRECTION(PORT,3,1);
	DIO_SET_PIN_DIRECTION(PORT,4,1);
	DIO_SET_PIN_DIRECTION(PORT,5,1);
	DIO_SET_PIN_DIRECTION(PORT,6,1);
	DIO_SET_PIN_DIRECTION(PORT,7,1);
	DIO_SET_PIN_DIRECTION('b',E,1);
	DIO_SET_PIN_DIRECTION('b',RS,1);
	DIO_SET_PIN_DIRECTION('b',RW,1);
	DIO_WRITE('b',RW,0);
	LCD_vSend_cmd(EIGHT_BITS);
	_delay_ms(1);
	LCD_vSend_cmd(DISPLAY_ON);
	_delay_ms(1);
	LCD_vSend_cmd(ClEAR_SCREEN);
	_delay_ms(10);
	LCD_vSend_cmd(ENTRY_MODE);
	_delay_ms(1);
	#elif defined four_bit_mode
	//write on low nipple
	DIO_SET_PIN_DIRECTION(PORT,0,1);
	DIO_SET_PIN_DIRECTION(PORT,1,1);
	DIO_SET_PIN_DIRECTION(PORT,2,1);
	DIO_SET_PIN_DIRECTION(PORT,3,1);
	DIO_SET_PIN_DIRECTION(PORT,4,1);
	DIO_SET_PIN_DIRECTION('b',E,1);
	DIO_SET_PIN_DIRECTION('b',RS,1);
	DIO_SET_PIN_DIRECTION('b',RW,1);
	DIO_WRITE('b',RW,0);
	LCD_vSend_cmd(RETURN_HOME);
	_delay_ms(10);
	LCD_vSend_cmd(FOUR_BITS);
	_delay_ms(1);
	LCD_vSend_cmd(DISPLAY_ON);
	_delay_ms(1);
	LCD_vSend_cmd(ClEAR_SCREEN);
	_delay_ms(10);
	LCD_vSend_cmd(ENTRY_MODE);
	_delay_ms(1);
	#endif
}
void  LCD_vEnable()
{	
	
	//sending falling edge
	DIO_WRITE('b',E,1);
	_delay_ms(2);
	DIO_WRITE('b',E,0);
	_delay_ms(2);
}
void LCD_vSend_cmd( char cmd)
{
	#if defined eight_bit_mode
		DIO_WRITE_PORT(PORT,cmd);
		DIO_WRITE('B',RS,0);//write to control register
		LCD_vEnable();
		_delay_ms(1);
	#elif defined four_bit_mode
		DIO_WRITE_LowNipple(PORT,cmd>>4); 
		DIO_WRITE('B',RS,0);
		LCD_vEnable();
		_delay_ms(1);
		DIO_WRITE_LowNipple(PORT,cmd);
		DIO_WRITE('B',RS,0);
		LCD_vEnable();
		_delay_ms(1);
	#endif
}
void LCD_vSend_char( char data)
{
	#if defined eight_bit_mode
		DIO_WRITE_PORT(PORT,data);
		DIO_WRITE('B',RS,1);//write to data register
		LCD_vEnable();
		_delay_ms(1);
	#elif defined four_bit_mode
		DIO_WRITE_LowNipple(PORT,data>>4);
		DIO_WRITE('B',RS,1);
		LCD_vEnable();
		_delay_ms(1);
		DIO_WRITE_LowNipple(PORT,data);
		DIO_WRITE('B',RS,1);
		LCD_vEnable();
		_delay_ms(1);
	#endif
}

void LCD_vSend_string(char *data)
{	static unsigned char counter=0;
	while((*data)!='\0')
	{
		LCD_vSend_char(*data);
		data++;
		/*counter++;
		if(counter==16)//if the string larger than 16 character, move to the next row
		{
			LCD_vMove_Cursor(2,1);
			LCD_vSend_char(PORT);
		}*/
	}
}
void LCD_vClear_Screen()
{
	LCD_vSend_cmd(0x01);
	_delay_ms(10);
		
}
void LCD_vReturn_Home()
{
	LCD_vSend_cmd(0x02);
	_delay_ms(10);
}
void LCD_vMove_Cursor(unsigned char row,unsigned char column)
{
	if(1==row)
	{
		LCD_vSend_cmd((0x80+column-1));
		_delay_ms(10);
	}
	else if(2==row)
	{
		LCD_vSend_cmd((0xc0+column-1));
		_delay_ms(10);
	}
	else
	{
		LCD_vReturn_Home();
		_delay_ms(10);
	}
}