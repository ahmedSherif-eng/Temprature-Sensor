#include<avr/io.h>
#include"bitwise.h"

void DIO_SET_PIN_DIRECTION(char port,char pin,char dir)
{
	switch(port)
	{
		case 'A':
		case 'a': (dir==0)?(CLEAR(DDRA,pin)):(SET(DDRA,pin));
		break;
		case 'B':
		case 'b': (dir==0)?(CLEAR(DDRB,pin)):(SET(DDRB,pin));
		break;
		case 'C':
		case 'c': (dir==0)?(CLEAR(DDRC,pin)):(SET(DDRC,pin));
		break;
		case 'D':
		case 'd': (dir==0)?(CLEAR(DDRD,pin)):(SET(DDRD,pin));
		break;
	}
}
void DIO_WRITE(char port,char pin,char val)
	{
		switch(port)
		{
			case 'a': 
			case'A':(val==1)?(SET(PORTA,pin)):(CLEAR(PORTA,pin));
			break;
			case 'b':
			case'B':(val==1)?(SET(PORTB,pin)):(CLEAR(PORTB,pin));
			break;
			case 'c':
			case'C':(val==1)?(SET(PORTC,pin)):(CLEAR(PORTC,pin));
			break;
			case 'd':
			case'D':(val==1)?(SET(PORTD,pin)):(CLEAR(PORTD,pin));
			break;
		}		
	}
void DIO_TOGGLE(char port,char pin)
	{
		switch(port)
		{
			case'a':
			case'A':(TOGGLE(PORTA,pin));
			break;
			case'b':
			case'B':(TOGGLE(PORTB,pin));
			break;
			case'C':
			case'c':(TOGGLE(PORTC,pin));
			break;
		}
	}

char DIO_READ(char port,char pin)
	{
		char return_value;
		switch(port)
		{
			case'a':
			case'A':return_value=READ(PINA,pin);
			break;
			case'b':
			case'B':return_value=READ(PINB,pin);
			break;
			case'c':
			case'C':return_value=READ(PINC,pin);
			break;
			case'd':
			case'D':return_value=READ(PIND,pin);
			break;
		}
		return return_value;
	}
void DIO_SET_PORT_DIRECTION(char port,char val)
	{
		switch(port)
		{
			case'a':
			case'A':DDRA=val;
			break;
			case'b':
			case'B':DDRB=val;
			break;
			case'C':
			case'c':DDRC=val;
			break;
			case'D':
			case'd':(DDRD=val);
			break;
		}
	}
void DIO_WRITE_PORT(char port,char val)
	{
		switch(port)
		{
			case'a':
			case'A':PORTA=val;
			break;
			case'b':
			case'B':PORTB=val;
			break;
			case'c':
			case'C':PORTC=val;
			break;
			case'd':
			case'D':PORTD=val;
			break;
		}
	}
void DIO_TOGGLE_PORT(char port)
	{
		switch(port)
		{
			case'a':
			case'A':PORTA^=0xff;
			break;
			case'b':
			case'B':PORTB^=0xff;
			break;
			case'c':
			case'C':PORTC^=0xff;
			break;
			case'd':
			case'D':PORTD^=0xff;
			break;
		}
	}	
void DIO_vConnectPullUp(char port,char pin,char connect)
{
	switch(port)
	{
		case'a':
		case'A':(connect==1)? (SET(PORTA,pin)):(CLEAR(PORTA,pin));
		break;
		case'b':
		case'B':(connect==1)? (SET(PORTB,pin)):(CLEAR(PORTB,pin));
		break;
		case'C':
		case'c':(connect==1)? (SET(PORTC,pin)):(CLEAR(PORTC,pin));
		break;	
		case'd':
		case'D':(connect==1)? (SET(PORTD,pin)):(CLEAR(PORTD,pin));
		break;
	}
}
void DIO_WRITE_LowNipple(unsigned char port,unsigned char val)
{
		val&=0x0f;
		switch(port)
		{	
			case'a':
			case 'A':
			PORTA&=0xf0;
			PORTA|=val;
			break;
			case 'B':
			case'b':
			PORTB&=0xf0;
			PORTB|=val;
			break;
			case'c':
			case 'C':
			PORTC&=0xf0;
			PORTC|=val;
			break;
			case 'D':
			case'd':
			PORTD&=0xf0;
			PORTD|=val;
			break;
		}
}
void DIO_WRITE_highNipple(unsigned char port,unsigned char val)
{
	val&=0x0f;
	val=val<<4;
	switch(port)
	{
		case'a':
		case 'A':
		PORTA&=0x0f;
		PORTA|=val;
		break;
		case 'B':
		case'b':
		PORTB&=0x0f;
		PORTB|=val;
		break;
		case'c':
		case 'C':
		PORTC&=0x0f;
		PORTC|=val;
		break;
		case 'D':
		case'd':
		PORTD&=0x0f;
		PORTD|=val;
		break;
	}
}