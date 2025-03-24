#include <REGX51.H>
#include <INTRINS.H>

void Delayxms(unsigned int x)		//@11.0592MHz
{
	unsigned char i, j;
	while(x--){
		_nop_();
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
	while(1)
	{
		P2=0x9F;  //1001 1111
		Delayxms(500);
		P2=0xFF;
		Delayxms(500);
		/*P2=0xFE;
		Delayxms(500);
		P2=0xFD;
		Delayxms(500);
		P2=0xFB;
		Delayxms(500);
		P2=0xF7;
		Delayxms(500);
		P2=0xEF;
		Delayxms(500);
		P2=0xDF;
		Delayxms(500);
		P2=0xBF;
		Delayxms(500);
		P2=0x7F;
		Delayxms(500);*/
	}
}