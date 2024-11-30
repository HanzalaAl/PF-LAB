// Q6. Write a program which perform following operations
// Dynamically allocate memory to read the contents of a file of unknown size.
//  Resize the buffer as needed while reading.
// Count the frequency of each word in the file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INITIAL_BUFFER_SIZE 1024
#define INITIAL_WORD_LIST_SIZE 10

typedef struct {
    char *word;
    int count;
} WordFreq;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

void addWord(WordFreq **wordList, int *wordCount, int *listSize, const char *word) {
    for (int i = 0; i < *wordCount; i++) {
        if (strcmp((*wordList)[i].word, word) == 0) {
            (*wordList)[i].count++;
            return;
        }
    }

    if (*wordCount >= *listSize) {
        *listSize *= 2;
        *wordList = realloc(*wordList, (*listSize) * sizeof(WordFreq));
        if (*wordList == NULL) {
            printf("Memory reallocation failed!\n");
            exit(1);
        }
    }

    (*wordList)[*wordCount].word = malloc(strlen(word) + 1);
    if ((*wordList)[*wordCount].word == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy((*wordList)[*wordCount].word, word);
    (*wordList)[*wordCount].count = 1;
    (*wordCount)++;
}

void freeWordList(WordFreq *wordList, int wordCount) {
    for (int i = 0; i < wordCount; i++) {
        free(wordList[i].word);
    }
    free(wordList);
}

int main() {
    char *buffer = malloc(INITIAL_BUFFER_SIZE);
    if (buffer == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    int bufferSize = INITIAL_BUFFER_SIZE;
    int bytesRead = 0;

    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        free(buffer);
        return 1;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (bytesRead >= bufferSize - 1) {
            bufferSize *= 2;
            buffer = realloc(buffer, bufferSize);
            if (buffer == NULL) {
                printf("Memory reallocation failed!\n");
                fclose(file);
                return 1;
            }
        }
        buffer[bytesRead++] = ch;
    }
    buffer[bytesRead] = '\0';
    fclose(file);

    WordFreq *wordList = malloc(INITIAL_WORD_LIST_SIZE * sizeof(WordFreq));
    if (wordList == NULL) {
        printf("Memory allocation failed!\n");
        free(buffer);
        return 1;
    }

    int wordCount = 0;
    int listSize = INITIAL_WORD_LIST_SIZE;

    char *token = strtok(buffer, " \t\n\r,.!?;:\"()");
    while (token != NULL) {
        toLowerCase(token);
        addWord(&wordList, &wordCount, &listSize, token);
        token = strtok(NULL, " \t\n\r,.!?;:\"()");
    }

    printf("Word frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordList[i].word, wordList[i].count);
    }

    freeWordList(wordList, wordCount);
    free(buffer);

    return 0;
}
