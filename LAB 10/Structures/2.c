// Write a program that use a structure to hold information about movies, such as title,
// genre, director, release year, and rating. Write a program that allows users to add new
// movies, search for movies by genre, and display all movie details.


#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 100

typedef struct {
    char title[30];
    char genre[30];
    char director[30];
    int releaseYear;
    float rating;
} Movie;

void addMovie(Movie movies[], int *count);
void searchByGenre(Movie movies[], int count);
void displayAllMovies(Movie movies[], int count);

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    do {
        printf("\n--- Movie Management System ---\n");
        printf("1. Add a New Movie\n");
        printf("2. Search Movies by Genre\n");
        printf("3. Display All Movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                searchByGenre(movies, movieCount);
                break;
            case 3:
                displayAllMovies(movies, movieCount);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Cannot add more movies. Maximum limit reached.\n");
        return;
    }

    printf("Enter title: ");
    scanf(" %[^\n]s", movies[*count].title);
    printf("Enter genre: ");
    scanf(" %[^\n]s", movies[*count].genre);
    printf("Enter director: ");
    scanf(" %[^\n]s", movies[*count].director);
    printf("Enter release year: ");
    scanf("%d", &movies[*count].releaseYear);
    printf("Enter rating: ");
    scanf("%f", &movies[*count].rating);

    (*count)++;
    printf("Movie added successfully.\n");
}

void searchByGenre(Movie movies[], int count) {
    char genre[30];
    int found = 0;

    printf("Enter genre to search: ");
    scanf(" %[^\n]s", genre);

    printf("\nMovies of genre '%s':\n", genre);
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].genre, genre) == 0) {
            printf("Title: %s, Director: %s, Year: %d, Rating: %.1f\n",
                   movies[i].title, movies[i].director, movies[i].releaseYear, movies[i].rating);
            found = 1;
        }
    }

    if (!found) {
        printf("No movies found in the genre '%s'.\n", genre);
    }
}

void displayAllMovies(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to display.\n");
        return;
    }

    printf("\nAll Movies:\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s, Genre: %s, Director: %s, Year: %d, Rating: %.1f\n",
               movies[i].title, movies[i].genre, movies[i].director, movies[i].releaseYear, movies[i].rating);
    }
}
