#include <lpc214x.h>

void UART0_Init(void)
{
 PLL0CON = 0;
 PLL0FEED=0xAA;
 PLL0FEED=0x55;
 VPBDIV = 1;
 // Fpclk = 12.000.000 MHz
 // DLM,DLH = Fpclk / (19200*16) = 39 = 0x27
 PINSEL0 |= 0x5; // Select UART0 RXD/TXD
 U0FCR = 0; // Disable FIFO's
 U0LCR = 0x83; // 8N1, enable Divisor latch bit
 U0DLL = 0x27; // baud rate fixed to 19200 @ PCLK = 12 Mhz
 U0DLM = 0;
 U0LCR = 3; // Disable Divisor latch bit
}
/*------------------------------------------------------------------*/
/* Function to send one char. to Serial Port */
void sout(unsigned char dat1)
{
 while(!(U0LSR & 0x20));//Wait for Tx Buffer Empty 
 U0THR = dat1;   //Send to UART1
}
/*-------------------------------------------------------*/

int main (void)
{  int dat; 
   UART0_Init();
 do
  { 
   if(U0LSR & 1)  /* Check for RDR (Receiver Data Ready)command */	
    {
       dat = U0RBR;// Receive Data from Srial Port
       sout(dat);  // Send Data to Srial Port
	}
   }while(1);
}
