#include <REGX52.H>
#include "Delay.h"
#include "MatrixLED.h"

void main()
{
	P2_5=0;
	while(1)
	{
		MatrixLED_ShowColumn(0,0x80);
		MatrixLED_ShowColumn(1,0x40);
		MatrixLED_ShowColumn(2,0x20);
		MatrixLED_ShowColumn(3,0x10);
	}
}