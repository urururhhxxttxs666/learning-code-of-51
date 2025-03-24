#include <REGX52.H>
#include "Key.h"
#include "Delay.h"
#include "Timer0.h"
#include "Nixie.h"

unsigned char KeyNum,Temp;


void main()
{
	Timer0_Init();
	P2_5=0;
	while (1)
	{
		KeyNum = Key();
		if(KeyNum)
		{
			Nixie_SetBuf(1,KeyNum);
		}
	}
}

void Timer0_Rountine() interrupt 1
{
	static unsigned int T0Count1=0,T0Count2 = 0;
	TL0 = 0x18; // 设置定时初始值
	TH0 = 0xFC; // 设置定时初始值
	T0Count1++;
	T0Count2++;
	if (T0Count1 >= 20)
	{
		T0Count1 = 0;
		Key_Loop();
	}
	if (T0Count2 >= 2)
	{
		T0Count2 = 0;
		Nixie_Loop();
	}
}