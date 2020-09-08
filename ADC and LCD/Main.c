
#include <AT89x51.h>
#include <stdio.h>
#include "ADC0831.h"
#include "lcd4bit.h"

void InitSystem()
{
	InitADC0831();
	init_lcd();
	gotoxy_lcd(1, 1);
}
void delay()
{
 int i,j;
 for(i=0;i<200;i++)
 {
  for(j=0;j<1000;j++)
  {}
 }
}
void main()
{
	unsigned char i1;
	unsigned char Msg1[20];
	unsigned int AverageValue1;
	unsigned char Sample1[5] = {0, 0, 0, 0, 0};

	unsigned char i2;
	unsigned char Msg2[20];
	unsigned int AverageValue2;
	unsigned char Sample2[5] = {0, 0, 0, 0, 0};

	InitSystem();
	while(1)
	{
		AverageValue1 = 0;
		for(i1 = 4; i1 > 0; i1 --)
		{
			Sample1[i1] = Sample1[i1 - 1];
			AverageValue1 += Sample1[i1];
		}
		Sample1[0] = ReadADC08311();
		AverageValue1 += Sample1[0];
		AverageValue1 /= 5;

			AverageValue2 = 0;
		for(i2 = 4; i2 > 0; i2 --)
		{
			Sample2[i2] = Sample2[i2 - 1];
			AverageValue2 += Sample2[i2];
		}
		Sample2[0] = ReadADC08312();
		AverageValue2 += Sample2[0];
		AverageValue2 /= 5;
		sprintf(Msg1, "     ADC1=%d", AverageValue1);
		gotoxy_lcd(1, 1);
		print_lcd(Msg1);
		sprintf(Msg2, "     ADC2=%d", AverageValue2);
		gotoxy_lcd(1, 2);
		print_lcd(Msg2);
		delay();
	
	}
}

