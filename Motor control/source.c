#include<reg52.h>
#include<stdio.h>

void delay(void);

sbit motor_pin_1 = P2^0;
sbit motor_pin_2 = P2^1;
sbit motor_pin_3 = P2^2;
sbit motor_pin_4 = P2^3;
sbit motor_pin_5 = P2^4;
sbit motor_pin_6 = P2^5;
sbit motor_pin_7 = P2^6;
sbit motor_pin_8 = P2^7;
void main()
{
 do
 {
   motor_pin_1 = 1;
	 motor_pin_2 = 0; //Rotates Motor Anit Clockwise
	  motor_pin_3 = 1;
	 motor_pin_4 = 0; //Rotates Motor Anit Clockwise
	 motor_pin_5 = 1;
	 motor_pin_6 = 0; //Rotates Motor Anit Clockwise
	  motor_pin_7 = 1;
	 motor_pin_8 = 0; //Rotates Motor Anit Clockwise
	 delay();
	 motor_pin_1 = 1;
	 motor_pin_2 = 1; //Stops Motor
	 	 motor_pin_3 = 1;
	 motor_pin_4 = 1; //Stops Motor
	  motor_pin_5 = 1;
	 motor_pin_6 = 1; //Stops Motor
	 	 motor_pin_7 = 1;
	 motor_pin_8 = 1; //Stops Motor
	 delay();
	 motor_pin_1 = 0;
	 motor_pin_2 = 1; //Rotates Motor Clockwise
	  motor_pin_3 = 0;
	 motor_pin_4 = 1; //Rotates Motor Clockwise
	  motor_pin_5 = 0;
	 motor_pin_6 = 1; //Rotates Motor Clockwise
	  motor_pin_7 = 0;
	 motor_pin_8 = 1; //Rotates Motor Clockwise
	 delay();
	 motor_pin_1 = 0;
	 motor_pin_2 = 0; //Stops Motor
	 	 motor_pin_3 = 0;
	 motor_pin_4 = 0; //Stops Motor
	 	 motor_pin_5 = 0;
	 motor_pin_6 = 0; //Stops Motor
	 	 motor_pin_7 = 0;
	 motor_pin_8 = 0; //Stops Motor
	 delay();

 }while(1);

}

void delay()
{
 int i,j;
 for(i=0;i<1000;i++)
 {
  for(j=0;j<1000;j++)
  {}
 }
}