
#include <AT89x51.h>
#include "lcd4bit.h"

sbit RS = P2^2;
sbit En = P2^3;
sbit D0 = P2^4;
sbit D1 = P2^5;
sbit D2 = P2^6;
sbit D3 = P2^7;

void init_lcd (void)
{
  RS = Lo;
  write_nibble_lcd(0x03);	delay_lcd();
  write_nibble_lcd(0x03);	delay_lcd();
  write_nibble_lcd(0x02);	delay_lcd();
  write_lcd(0x28);
  write_lcd(0x06);
  write_lcd(0x0c);
  write_lcd(0x01);
}  

void gotoxy_lcd(unsigned char col,unsigned char line)
{
	RS = Lo;
	if (line == 1)
		write_lcd(0x7f+col);
	if (line == 2)
		write_lcd(0xbf+col);
}

void putc_lcd(unsigned char byte)
{
   RS = Hi;
   write_lcd(byte);
}

void print_lcd(char String[])
{
	int i = 0;
	do
   	{
		putc_lcd(String[i]);
    	i++;
	}
	while(String[i] != '\0');
}

void delay_lcd (void)
{
	int del1,del2;
  	for(del1=0;del1<10;del1++)
  	{
    	for(del2=0;del2<200;del2++);
  	}
}

void write_lcd(unsigned char Val)
{
	write_nibble_lcd(Val >> 4);
	write_nibble_lcd(Val);
	delay_lcd();
}

void write_nibble_lcd(unsigned char Val)
{
	En = Hi;
	D0 = D1 = D2 = D3 = 0;
	if(Val & 0x01)
		D0 = 1;
	if(Val & 0x02)
		D1 = 1;
	if(Val & 0x04)
		D2 = 1;
	if(Val & 0x08)
		D3 = 1;
	En = Lo;
}

