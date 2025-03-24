#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "MatrixKey.h"

unsigned char KeyNum;
unsigned int PassWord;
int count=0;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"password:");
	LCD_ShowNum(2,1,0000,4);
	while(1)
	{
		KeyNum=MatrixKey();
		if(KeyNum)
		{
			if(KeyNum<=10)
			{
				if(count<4)
				{
					PassWord*=10;
					PassWord+=KeyNum%10;
					count++;
					LCD_ShowNum(2,1,PassWord,4);
				}
			}
			if(KeyNum==11)
			{
				if(PassWord==1111)
				{
					LCD_ShowString(1,12,"ON ");
					PassWord=count=0;
					LCD_ShowNum(2,1,PassWord,4);
				}
				else
				{
					LCD_ShowString(1,12,"ERR");
					PassWord=count=0;
					LCD_ShowNum(2,1,PassWord,4);
				}
			}
			if(KeyNum==12)
			{
				PassWord=count=0;
				LCD_ShowString(1,12,"    ");
				LCD_ShowNum(2,1,PassWord,4);
			}
			
		}
	}
}
