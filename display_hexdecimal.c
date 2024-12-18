#include <LPC214X.H>

#define DS3   1<<13     // P0.13
#define DS4   1<<12     // P0.12
#define SEG_CODE 0xFF<<16 // Segment Data from P0.16 to P0.23

unsigned char const seg_hexadecimal[] = {
    0x3F, // '0'
    0x06, // '1'
    0x5B, // '2'
    0x4F, // '3'
    0x66, // '4'
    0x6D, // '5'
    0x7D, // '6'
    0x07, // '7'
    0x7F, // '8'
    0x6F, // '9'
    0x77, // 'A'
    0x7C, // 'b'
    0x39, // 'C'
    0x5E, // 'd'
    0x79, // 'E'
    0x71  // 'F'
};

void delayms(int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < 5035; j++) {;}  // Delay for 60 MHz clock
    }
}

int main(void) {
    int count;

    PINSEL0 = 0; // Configure Port0 as General Purpose IO => P0.0 to P0.15
    PINSEL1 = 0; // Configure Port0 as General Purpose IO => P0.16 to P0.31

    IODIR0 = SEG_CODE | DS3 | DS4; // Configure Segment data & Select signal as output

    IOSET0 = SEG_CODE | DS3;  // Disable DS3 display
    IOCLR0 = DS4;  // Enable DS4 Display

    while (1) {
        for (count = 0; count < 16; count++) {
            IOCLR0 = SEG_CODE;
            IOSET0 = seg_hexadecimal[count] << 16;
            delayms(1000); // 1 sec delay
        }
    }
}
