// Write a program that uses structures to manage flight information, including flight
// number, departure city, destination city, date, and available seats. Create functionalities
// to book a seat and display flight details.

#include <stdio.h>
#include <string.h>

#define MAX_FLIGHTS 5

struct Flight {
    int flightNumber;
    char departureCity[50];
    char destinationCity[50];
    char date[15];
    int availableSeats;
};

void displayFlightDetails(struct Flight flights[], int totalFlights);
void bookSeat(struct Flight flights[], int totalFlights);

int main() {
    struct Flight flights[MAX_FLIGHTS] = {
        {101, "New York", "Los Angeles", "2024-12-01", 50},
        {102, "Chicago", "Houston", "2024-12-02", 30},
        {103, "San Francisco", "Seattle", "2024-12-03", 20},
        {104, "Miami", "Dallas", "2024-12-04", 25},
        {105, "Boston", "Atlanta", "2024-12-05", 15}
    };

    int choice;
    do {
        printf("\n--- Flight Management System ---\n");
        printf("1. Display Flight Details\n");
        printf("2. Book a Seat\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayFlightDetails(flights, MAX_FLIGHTS);
                break;
            case 2:
                bookSeat(flights, MAX_FLIGHTS);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

void displayFlightDetails(struct Flight flights[], int totalFlights) {
    printf("\nFlight Details:\n");
    printf("----------------------------------------------------------\n");
    printf("Flight No | Departure      | Destination    | Date       | Seats\n");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < totalFlights; i++) {
        printf("%9d | %-14s | %-14s | %-10s | %5d\n",
               flights[i].flightNumber, 
               flights[i].departureCity, 
               flights[i].destinationCity, 
               flights[i].date, 
               flights[i].availableSeats);
    }
}

void bookSeat(struct Flight flights[], int totalFlights) {
    int flightNumber, found = 0;

    printf("\nEnter the flight number to book a seat: ");
    scanf("%d", &flightNumber);

    for (int i = 0; i < totalFlights; i++) {
        if (flights[i].flightNumber == flightNumber) {
            found = 1;
            if (flights[i].availableSeats > 0) {
                flights[i].availableSeats--;
                printf("Seat successfully booked on flight %d.\n", flightNumber);
                printf("Remaining seats: %d\n", flights[i].availableSeats);
            } else {
                printf("Sorry, no seats are available on flight %d.\n", flightNumber);
            }
            break;
        }
    }

    if (!found) {
        printf("Flight number %d not found.\n", flightNumber);
    }
}
