// Design a structure to store information about travel packages, including package name,
// destination, duration, cost, and number of seats available. Write a program that allows
// users to book a travel package and display available packages.

#include <stdio.h>
#include <string.h>

#define MAX_PACKAGES 10

typedef struct {
    char packageName[50];
    char destination[50];
    int duration; 
    float cost;    
    int availableSeats;
} TravelPackage;

void displayPackages(TravelPackage packages[], int packageCount);
void bookPackage(TravelPackage packages[], int packageCount);

int main() {
    TravelPackage packages[MAX_PACKAGES] = {
        {"Holiday in Paris", "Paris", 7, 1500.00, 10},
        {"Beach Vacation", "Hawaii", 5, 1200.00, 5},
        {"Adventure in Alps", "Switzerland", 10, 2000.00, 3}
    };
    
    int packageCount = 3;
    int choice;

    do {
        printf("\nTravel Agency Management System\n");
        printf("1. Display available travel packages\n");
        printf("2. Book a travel package\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayPackages(packages, packageCount);
                break;
            case 2:
                bookPackage(packages, packageCount);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

void displayPackages(TravelPackage packages[], int packageCount) {
    if (packageCount == 0) {
        printf("No packages available.\n");
        return;
    }

    printf("\nAvailable Travel Packages:\n");
    for (int i = 0; i < packageCount; i++) {
        printf("Package %d:\n", i + 1);
        printf("Package Name: %s\n", packages[i].packageName);
        printf("Destination: %s\n", packages[i].destination);
        printf("Duration: %d days\n", packages[i].duration);
        printf("Cost: $%.2f\n", packages[i].cost);
        printf("Available Seats: %d\n\n", packages[i].availableSeats);
    }
}

void bookPackage(TravelPackage packages[], int packageCount) {
    int choice, seatsToBook;

    printf("Enter the number of the package you want to book: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > packageCount) {
        printf("Invalid package number.\n");
        return;
    }

    choice--;
    printf("Enter the number of seats you want to book: ");
    scanf("%d", &seatsToBook);

    if (seatsToBook > packages[choice].availableSeats) {
        printf("Sorry, not enough seats available.\n");
    } else {
        packages[choice].availableSeats -= seatsToBook;
        printf("Booking successful! You have booked %d seats on the '%s' package.\n",
               seatsToBook, packages[choice].packageName);
        printf("Remaining seats: %d\n", packages[choice].availableSeats);
    }
}


