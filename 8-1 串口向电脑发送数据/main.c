#include <REGX52.H>
#include "Delay.h"
#include "UART.h"

unsigned char Sec=0;

void main()
{
	UART_Init();
	
	while(1)
	{
		UART_SendBtye(Sec);
		Sec++;
		Delay(1000);
	}
}