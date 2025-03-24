#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"
#include "LCD1602.h"

unsigned char Num;
unsigned int Time;

void main()
{
	
	LCD_Init();
	Int0_Init();
	Timer0_Init();
	Timer0_SetCounter(0);
	Timer0_Run(1);
	Delay(10);
	Time=Timer0_GetCounter();
	LCD_ShowNum(1,1,Time,5);
	
	while(1)
	{
		
	}
}

