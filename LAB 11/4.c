#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Passenger {
    int passengerId;
    int pclass;
    char name[100];
    char sex[10];
    int age;
    int sibsp;
    int parch;
    char ticket[20];
    float fare;
    char cabin[20];
    char embarked[10];
    int survived;
};

void loadTitanicData(char *filename, struct Passenger passengers[], int *count) {
    FILE *file = fopen(filename, "r");
    char line[200];
    *count = 0;
    
    while (fgets(line, sizeof(line), file)) {
        if (*count > 0) {
            struct Passenger p;
            sscanf(line, "%d,%d,%99[^,],%9[^,],%d,%d,%d,%19[^,],%f,%19[^,],%9s,%d",
                &p.passengerId, &p.pclass, p.name, p.sex, &p.age, &p.sibsp, &p.parch,
                p.ticket, &p.fare, p.cabin, p.embarked, &p.survived);
            passengers[*count - 1] = p;
        }
        (*count)++;
    }
    fclose(file);
}

float calculateAverageAge(struct Passenger passengers[], int count) {
    int totalAge = 0;
    for (int i = 0; i < count; i++) {
        totalAge += passengers[i].age;
    }
    return (float) totalAge / count;
}

float calculateSurvivalRate(struct Passenger passengers[], int count, char *sex) {
    int totalSurvivors = 0;
    int totalPassengers = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(passengers[i].sex, sex) == 0) {
            totalPassengers++;
            if (passengers[i].survived == 1) {
                totalSurvivors++;
            }
        }
    }
    return (float) totalSurvivors / totalPassengers;
}

void displaySurvivors(struct Passenger passengers[], int count) {
    printf("List of survivors:\n");
    for (int i = 0; i < count; i++) {
        if (passengers[i].survived == 1) {
            printf("Name: %s, Age: %d, Class: %d\n", passengers[i].name, passengers[i].age, passengers[i].pclass);
        }
    }
}

void displayMissingCabins(struct Passenger passengers[], int count) {
    printf("Passengers with missing cabin details:\n");
    for (int i = 0; i < count; i++) {
        if (strcmp(passengers[i].cabin, "") == 0) {
            printf("Name: %s, Age: %d, Class: %d\n", passengers[i].name, passengers[i].age, passengers[i].pclass);
        }
    }
}

int main() {
    struct Passenger passengers[1000];
    int count = 0;
    
    loadTitanicData("titanic.csv", passengers, &count);
    
    float avgAge = calculateAverageAge(passengers, count);
    printf("Average age of all passengers: %.2f\n", avgAge);
    
    float maleSurvivalRate = calculateSurvivalRate(passengers, count, "male");
    printf("Survival rate of males: %.2f\n", maleSurvivalRate);
    
    float femaleSurvivalRate = calculateSurvivalRate(passengers, count, "female");
    printf("Survival rate of females: %.2f\n", femaleSurvivalRate);
    
    displaySurvivors(passengers, count);
    displayMissingCabins(passengers, count);
    
    return 0;
}
