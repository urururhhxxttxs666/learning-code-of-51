#include <REGX52.H>
#include "AT24C02.h"
#include "LCD1602.h"
#include "Key.h"
#include "Delay.h"

unsigned char KeyNum;
unsigned int Num;

void main()
{
	LCD_Init();
	LCD_ShowNum(1,1,Num,4);
	while(1)
	{
		KeyNum=Key();
		if(KeyNum==1)
		{
			Num++;
			LCD_ShowHexNum(1,1,Num,4);
		}
		if(KeyNum==2)
		{
			Num--;
			LCD_ShowHexNum(1,1,Num,4);
		}
		if(KeyNum==4)
		{
			AT24C02_WriteByte(0,Num%256);
			Delay(10);
			AT24C02_WriteByte(1,Num/256);
			Delay(10);
			LCD_ShowString(2,1,"Write");
			Delay(1000);
			LCD_ShowString(2,1,"     ");
			
		}
		if(KeyNum==3)
		{
			LCD_ShowHexNum(1,6,AT24C02_ReadByte(1),2);
			LCD_ShowHexNum(1,8,AT24C02_ReadByte(0),2);
			Num=AT24C02_ReadByte(0);
			Num|=AT24C02_ReadByte(1)<<8;
			LCD_ShowHexNum(1,1,Num,4);
			LCD_ShowString(2,1,"Read");
			Delay(1000);
			LCD_ShowString(2,1,"     ");
		}
	}
}