// 3. Create a program with a constant that defines the maximum allowable temperature (in
// Celsius). Write a function to compare input temperatures and use a static variable to
// count how many times temperatures exceeded the limit.

#include <stdio.h>

#define MAX_TEMPERATURE 35.0

void checkTemperature(float temperature);

int main() {
    float temp;
    char choice;

    do {
        printf("Enter the temperature (in Celsius): ");
        scanf("%f", &temp);

        checkTemperature(temp);

        printf("Do you want to enter another temperature? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

void checkTemperature(float temperature) {
    static int exceedCount = 0;

    if (temperature > MAX_TEMPERATURE) {
        exceedCount++;
        printf("Warning: Temperature %.2f exceeds the maximum limit of %.2f!\n", temperature, MAX_TEMPERATURE);
    } else {
        printf("Temperature %.2f is within the safe range.\n", temperature);
    }

    printf("Number of times temperature exceeded the limit: %d\n", exceedCount);
}
