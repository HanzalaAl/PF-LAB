// 1. Write a program that initializes a 2D character array with a list of words. Then, take a
// word as input from the user and check if it exists in the array. Display "Found" if it’s there,
// otherwise display "Not Found".

#include <stdio.h>
#include <string.h>

int main() {
    int found = 0;
    char fruits[5][20] = {
        "apple", 
        "banana", 
        "cherry", 
        "date", 
        "raspberry"
    };

    char search[20];
    printf("Enter the fruit you want to search: ");
    scanf("%s", search);

    for (int i = 0; i < 5; i++) {
        if (strcmp(fruits[i], search) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    return 0;
}

