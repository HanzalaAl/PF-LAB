// Create a C program that defines a constant for the conversion factor of meters to
// kilometers. Use a static variable in a function to count how many times the function is
// called.

#include <stdio.h>

#define CONVERSION_FACTOR 1000.0

void convertToKilometers(float meters);

int main() {
    float meters;
    convertToKilometers(1500.0);
    convertToKilometers(2500.0);
    convertToKilometers(3200.0);
    return 0;
}

void convertToKilometers(float meters) {
    static int callCount = 0;
    callCount++;
    float kilometers = meters / CONVERSION_FACTOR;
    printf("Conversion %d: %.2f meters = %.2f kilometers\n", callCount, meters, kilometers);
}
