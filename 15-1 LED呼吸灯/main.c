#include <REGX52.H>

sbit LED=P2^0;
unsigned char Time,i;

void Delay(unsigned char i)
{
	while(i--);
}

void main()
{
	while(1)
	{
		for(Time=0;Time<100;Time++)
		{
			for(i=0;i<20;i++)
			{
				LED=1;
				Delay(Time);
				LED=0;
				Delay(100-Time);
			}
		}
		for(;Time>0;Time--)
		{
			for(i=0;i<20;i++)
			{
				LED=1;
				Delay(Time);
				LED=0;
				Delay(100-Time);
			}
		}
	}
}