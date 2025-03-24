#include <REGX52.H>
#include "Delay.h"
#include "UART.h"

unsigned char Sec=0;

void main()
{
	UART_Init();
	
	while(1)
	{
//		UART_SendBtye(Sec);
//		Sec++;
//		Delay(1000);
	}
}

void UART_Routine() interrupt 4
{
	if(RI==1)
	{
		P2=SBUF;
		UART_SendBtye(SBUF);
		RI=0;
	}
}