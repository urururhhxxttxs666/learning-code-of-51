#include <REGX52.H>


void Delay(unsigned int x)		//@11.0592MHz
{
	unsigned char i, j;
	while(x--){
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}
}

void main()
{
	unsigned char LED=0;
	P2=~0x01;
	while(1)
	{
		if(P3_0==0)
		{
			Delay(20);
			while(P3_0==0);
			Delay(20);
			
			LED++;
			if(LED>=8) LED=0;
			P2=~(0x01<<LED);
		}
		
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			
			LED--;
			if(LED>=8) LED=7;
			P2=~(0x01<<LED);
		}
	}
}