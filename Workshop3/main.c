/*
 *****************************************************************
 * Name: Manav Patel                                             *
 * Email: patmanav@sheridancollege.ca                            *
 * Student Id: 991500582                                         *
 * Date: 29-09-2023                                              *
 *                                                               *
 *****************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Movie.h"
#include "utils.h"

void searchMovies(Movie* m, int size);

int main(void) {
    
    Movie m[100];
    int num = 0;
    char yes;
    FILE* file = fopen("movies.dat", "r");
    

    while (num < 100 && loadMovie(&m[num], file)) {
        list(&m[num], num + 1);
        num++;
    }

    fclose(file);

    printf("Searching for a movie based on title... ");
    do {
        searchMovies(m, num);
        printf("Another Search? (y)es/(n)o: ");
        yes = getchar();
        while (getchar() != '\n');
    } while (yes == 'y' || yes == 'Y');

    
    return 0;
}

void searchMovies(Movie* m, int size) {
    char title[51];
    int i;
    int found;
    printf("Searching for a movie based on title...\n");
    printf("Title: ");
    (void)scanf("%[^\n]", title);

    for (found = 0, i = 0; i < size; i++) {
        if (strstr(getMovieTitle(&m[i]), title)) {
            printf("%d ============================\n", ++found);
            display(&m[i]);
        }
    }
    while (getchar() != '\n');
}
