// Create a structure to store details about cars in a dealership, including make, model,
// year, price, and mileage. Write a program that allows users to add new cars, display a
// list of available cars, and search for cars by make or model.

#include <stdio.h>
#include <string.h>

#define MAX_CARS 100

typedef struct {
    char make[30];
    char model[30];
    int year;
    float price;
    float mileage;
} Car;

void addCar(Car cars[], int *carCount);
void displayCars(Car cars[], int carCount);
void searchCars(Car cars[], int carCount);

int main() {
    Car cars[MAX_CARS];
    int carCount = 0;
    int choice;

    do {
        printf("\nCar Dealership Management System\n");
        printf("1. Add a new car\n");
        printf("2. Display all cars\n");
        printf("3. Search for cars by make or model\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCar(cars, &carCount);
                break;
            case 2:
                displayCars(cars, carCount);
                break;
            case 3:
                searchCars(cars, carCount);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addCar(Car cars[], int *carCount) {
    if (*carCount >= MAX_CARS) {
        printf("Car list is full. Cannot add more cars.\n");
        return;
    }

    printf("Enter car make: ");
    scanf("%s", cars[*carCount].make);
    printf("Enter car model: ");
    scanf("%s", cars[*carCount].model);
    printf("Enter car year: ");
    scanf("%d", &cars[*carCount].year);
    printf("Enter car price: ");
    scanf("%f", &cars[*carCount].price);
    printf("Enter car mileage: ");
    scanf("%f", &cars[*carCount].mileage);

    (*carCount)++;
    printf("Car added successfully!\n");
}

void displayCars(Car cars[], int carCount) {
    if (carCount == 0) {
        printf("No cars available.\n");
        return;
    }

    printf("\nAvailable Cars:\n");
    for (int i = 0; i < carCount; i++) {
        printf("Car %d:\n", i + 1);
        printf("Make: %s\n", cars[i].make);
        printf("Model: %s\n", cars[i].model);
        printf("Year: %d\n", cars[i].year);
        printf("Price: %.2f\n", cars[i].price);
        printf("Mileage: %.2f\n\n", cars[i].mileage);
    }
}

void searchCars(Car cars[], int carCount) {
    char keyword[30];
    int found = 0;

    printf("Enter make or model to search: ");
    scanf("%s", keyword);

    printf("\nSearch Results:\n");
    for (int i = 0; i < carCount; i++) {
        if (strstr(cars[i].make, keyword) || strstr(cars[i].model, keyword)) {
            printf("Car %d:\n", i + 1);
            printf("Make: %s\n", cars[i].make);
            printf("Model: %s\n", cars[i].model);
            printf("Year: %d\n", cars[i].year);
            printf("Price: %.2f\n", cars[i].price);
            printf("Mileage: %.2f\n\n", cars[i].mileage);
            found = 1;
        }
    }

    if (!found) {
        printf("No cars found matching '%s'.\n", keyword);
    }
}
