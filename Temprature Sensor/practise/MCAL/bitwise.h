
/*
 * bitwise.h
 *
 * Created: 9/16/2022 1:58:59 PM
 *  Author: Ahmed Sherif
 */ 
#define u8 unsigned char
#define s8 signed char
#define u16 unsigned int
#define s16 signed int
#define SET(var,bit) var|=(1<<bit)
#define TOGGLE(var,bit) var^=(1<<bit)
#define CLEAR(var,bit) var&=~(1<<bit)
#define READ(var,bit) ((var&(1<<bit))>>bit)//((x&(1<<7))>>7)

