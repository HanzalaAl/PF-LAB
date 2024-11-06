// 1. Create a program that accepts a 2D array of strings (e.g., 5 words with a max length of 20
// characters each). Determines if each word (row) is a palindrome. Outputs “Palindrome” or “Not
// Palindrome” for each word. A palindrome is a word that reads the same forward and backward.
// For example: "madam", "racecar", "level", "radar".

#include <stdio.h>
#include <string.h>

int main() {
    char words[5][20];
    char reverse[5][20];

    printf("Enter 5 words (each up to 20 characters):\n");

    for (int i = 0; i < 5; i++) {
        fgets(words[i], 20, stdin);
        words[i][strcspn(words[i], "\n")] = '\0';
    }

    for (int i = 0; i < 5; i++) {
        int len = strlen(words[i]);
        int j = 0;

        for (int k = len - 1; k >= 0; k--) {
            reverse[i][j++] = words[i][k];
        }
        reverse[i][j] = '\0';
    }

    for (int i = 0; i < 5; i++) {
        if (strcmp(words[i], reverse[i]) == 0) {
            printf("%s is a Palindrome\n", words[i]);
        } else {
            printf("%s is not a Palindrome\n", words[i]);
        }
    }

    return 0;
}
