#include <lpc214x.h>

void delay(unsigned int count);      // Function for generating a delay

void generate_square_wave(void);     // Function to generate square waveform

int main(void) {
    // Initialize DAC on P0.25
    PINSEL1 |= (1 << 19);   // Configure P0.25 as DAC output

    while (1) {
        generate_square_wave();      // Generate square wave
        delay(50000);                // Small delay between waveform switching
    }
}

void delay(unsigned int count) {
    unsigned int i, j;
    for (i = 0; i < count; i++) {
        for (j = 0; j < 6000; j++);  // Approximate delay
    }
}

// Function to generate square waveform using DAC
void generate_square_wave(void) {
    unsigned int high = 1023 << 6;   // DAC value for maximum output
    unsigned int low = 0 << 6;       // DAC value for minimum output

    for (int i = 0; i < 100; i++) {
        DACR = high;  // Set DAC to maximum (High)
        delay(10000); // Hold for some time to create the high part of the square wave

        DACR = low;   // Set DAC to minimum (Low)
        delay(10000); // Hold for some time to create the low part of the square wave
    }
}
