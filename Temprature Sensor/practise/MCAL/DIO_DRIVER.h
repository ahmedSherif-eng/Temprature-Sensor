#ifndef DIO_DRIVER
#define DIO_DRIVER

void DIO_SET_PIN_DIRECTION(char port,char pin,char dir);
/*  Name: DIO_SET_PIN_DIRECTION
 *  Description: Set Desired Pin on Desired Port to Desired Value
 *  Arguments:   First Argument:   u8port,        options(A,a,b,B,c,C,d,D)
 *               Second Argument:  u8pin,         options(from 0 to 7)
 *               Third Argument: u8dir,         options(0 for input,1 for output)
 *
 *  Return: void */
void DIO_WRITE(char port,char pin,char val);
/*  Name: DIO_WRITE
 *  Description: Write the desired value on a pin in a specific port that already set to output
 *  Arguments:   First Argument:   u8port,        options(A,a,b,B,c,C,d,D)
 *               Second Argument:  u8pin,         options(from 0 to 7)
 *               Third Argument: u8val,         options(0 for low,1 for high)
 *
 *  Return: void */
void DIO_TOGGLE(char port,char pin);
/*  Name: DIO_TOGGLE
 *  Description: Toggle specified pin to the opposite value 
 *  Arguments:   First Argument:   u8port,        options(A,a,b,B,c,C,d,D)
 *               Second Argument:  u8pin,         options(from 0 to 7)
 *
 *  Return: void */
char DIO_READ(char port,char pin);
/*  Name: DIO_READ
 *  Description: Read value of an input pin
 *  Arguments:   First Argument:   u8port,        options(A,a,b,B,c,C,d,D)
 *               Second Argument:  u8pin,         options(from 0 to 7)
 *
 *  Return: u8 */
void DIO_SET_PORT_DIRECTION(char port,char val);
/*  Name: DIO_SET_Port_DIRECTION
 *  Description: Set Desired Port to Desired Value
 *  Arguments:   First Argument:   u8port,        options(A,a,b,B,c,C,d,D)
 *               Second Argument: u8val,         options(0x00 for all input,0xff for all output)
 *
 *  Return: void */
void DIO_WRITE_PORT(char port,char val);
/*  Name: DIO_WRITE_PORT
 *  Description: Write value on a specified port
 *  Arguments:   First Argument:   u8port,        options(A,a,b,B,c,C,d,D)
 *               Second Argument:  u8val,         options(from 0x00 to 0xff)
 *
 *  Return: void */
void DIO_TOGGLE_PORT(char port);
/*  Name: DIO_TOGGLE_PORT
 *  Description: Toggle the whole value of a port
 *  Arguments:   First Argument:   u8port,        options(A,a,b,B,c,C,d,D)
 *
 *  Return: void */
void DIO_vConnectPullUp(char port,char pin,char connect);
/*  Name: DIO_vConnectPullUp
 *  Description: write 1 on the desired pin on the desired port that already set to be input
 *  Arguments:   First Argument:   u8port,        options(A,a,b,B,c,C,d,D)
 *               Second Argument:  u8pin,         options(from 0 to 7)
 *
 *  Return: void */
void DIO_WRITE_LowNipple(unsigned char port,unsigned char val);
void DIO_WRITE_highNipple(unsigned char port,unsigned char val);
#endif