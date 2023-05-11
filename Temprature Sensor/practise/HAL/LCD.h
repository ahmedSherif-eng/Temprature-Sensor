#ifndef LCD_H
#define LCD_H
#define four_bit_mode
#define EIGHT_BITS		0x38
#define FOUR_BITS		0x28
#define ClEAR_SCREEN	0x01
#define RETURN_HOME		0x02
#define	DISPLAY_ON		0x0c
#define ENTRY_MODE		0x06
#define RS				1
#define E				0
#define RW				2
#define PORT			'c'			
void LCD_vInit();
void LCD_vEnable();
void LCD_vSend_cmd( char cmd);
void LCD_vSend_char( char data);
void LCD_vSend_string(char *data);
void LCD_vReturn_Home();
void LCD_vClear_Screen();
void LCD_vMove_Cursor(unsigned char row,unsigned char column);
#endif