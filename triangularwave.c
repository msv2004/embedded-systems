#include <lpc214x.h>

void delay(unsigned int count);      // Function for generating a delay

void generate_triangle_wave(void);   // Function to generate triangular waveform

int main(void) {
    // Initialize DAC on P0.25
    PINSEL1 |= (1 << 19);   // Configure P0.25 as DAC output

    while (1) {
        generate_triangle_wave();    // Generate triangular wave
        delay(50000);                // Small delay between waveform switching
    }
}

void delay(unsigned int count) {
    unsigned int i, j;
    for (i = 0; i < count; i++) {
        for (j = 0; j < 6000; j++);  // Approximate delay
    }
}

// Function to generate triangular waveform using DAC
void generate_triangle_wave(void) {
    unsigned int i;

    // Incrementing part of the triangle
    for (i = 0; i < 1023; i++) {
        DACR = (i << 6);  // Write to DAC (10-bit left justified)
        delay(100);       // Delay to control waveform frequency
    }

    // Decrementing part of the triangle
    for (i = 1023; i > 0; i--) {
        DACR = (i << 6);  // Write to DAC
        delay(100);       // Delay to control waveform frequency
    }
}
