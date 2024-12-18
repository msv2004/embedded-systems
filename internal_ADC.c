#include <LPC214X.H>

#define LEDS  0xFF<<8   //LED => P0.8 to P0.15

/////////////////////////////////////////
/*--- ADC Signal Declaration */
/////////////////////////////////////////
#define AD0_1 1<< 24
#define CLK_DIV 1<<8
#define PDN 1<<21
#define SOC 1<<24
#define BURST 1<<16
#define DONE 1<<31

/*-----------------------------------------------------------*/
//Delay Program
//Input - delay value in milli seconds
void delay(unsigned int k)  	
{
	unsigned int i,j;
	for (j=0; j<k; j++)
		for(i = 0; i<=800; i++);
}
/*-----------------------------------------------------------*/
void adc_init()
{
unsigned long int ADC_CH;

	 ADC_CH = 0 | 1 << 1; //Channel AD0.1             
     AD0CR = SOC | PDN | CLK_DIV | ADC_CH | BURST ; 
}
/*-----------------------------------------------------------*/
unsigned int adc_read( unsigned char channel) 
{
	  unsigned int aval;
	  unsigned long int val;
   
     if (channel == 1) val = AD0DR1;
     else if (channel == 2) val = AD0DR2;
     else if (channel == 3) val = AD0DR3;
     
     val = val >> 6;
     val = val & 0x3FF; 
     aval = val;
     return (aval);
}	
/*-----------------------------------------------------------*/ 
//////////////////////////
/*----Main Program------*/
//////////////////////////
int main(void)
{
unsigned int tp1;

  IODIR0   = LEDS; //Configure Port0 as output Port
  PINSEL0 = 0; //Configure Port0 as General Purpose IO  
  PINSEL1 = 0 | AD0_1; // Enable AD0.1
 
    adc_init(); //Initialise on-chip ADC
     
 do
  {  tp1 = adc_read(1); // Channel AD0 0.1
		 tp1 = tp1 >> 2;  // ADC 10 bit But LED 8bit, Truncate lsb 2 bits  
     IOSET0 =  LEDS;  //Switch OFF all LEDS
     IOCLR0 = tp1 << 8;  //Set VAlue
     delay(1000);
	 
	 
  }while(1);   
  
}
