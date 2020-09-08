
#include "ADC0831.H"
#include <AT89x51.h>

sbit adc_CS1 = P0^2;
sbit adc_CLK1 = P0^3;
sbit adc_DATA1 = P0^4;

sbit adc_CS2 = P0^5;
sbit adc_CLK2 = P0^6;
sbit adc_DATA2 = P0^7;
void InitADC0831()
{
	adc_CLK1 = 0;
	adc_CS1 = 1;
	adc_DATA1 = 1;

	adc_CLK2 = 0;
	adc_CS2 = 1;
	adc_DATA2 = 1;
}

unsigned char ReadADC08311()
{
	unsigned char Data1;
	unsigned char i;
	adc_CS1 = 0;
	;;;;;;;
	for(i = 0; i < 10; i ++)
	{
		adc_CLK1 = 1;;;;;;;;
		Data1 <<= 1;
		Data1 |= adc_DATA1;
		adc_CLK1 = 0;;;;;;;;
	}
	adc_CS1 = 1;
	return Data1;
}

unsigned char ReadADC08312()
{
	unsigned char Data2;
	unsigned char i;
	adc_CS2 = 0;
	;;;;;;;
	for(i = 0; i < 10; i ++)
	{
		adc_CLK2 = 1;;;;;;;;
		Data2 <<= 1;
		Data2 |= adc_DATA2;
		adc_CLK2 = 0;;;;;;;;
	}
	adc_CS2 = 1;
	return Data2;
}
