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
#include "Movie.h"

int loadMovie(Movie* mptr, FILE* fptr) {

	return (fscanf(fptr, "%[^\t]\t%d\t%3[^\t]\t%d\t%[^\t]\t%f\n", 
		mptr->title, &mptr->year,mptr-> rating, 
		&mptr->duration, mptr->genre, &mptr->c_rating) == 6);
}

void list(const Movie* mptr, int row) {

	putchar('|');
	printf("%3d ",row);
	putchar('|');
	putchar(' ');
	printInWidth(mptr->title, 20);
	putchar(' ');
	putchar('|');
	printf("%5d ", mptr->year);
	putchar('|');
	printf("%5s ", mptr->rating);
	putchar('|');
	printf(" %2d:%-2.2d ", mptr->duration / 60, min(mptr->duration));
	putchar('|');
	putchar(' ');
	printInWidth(mptr->genre, 25);
	putchar(' ');
	putchar('|');
	printf("%5.1f ", mptr->c_rating);
	putchar('|');
	printf("\n");
}

void display(const Movie* m) {
	printf("Title: %s\n",m->title);
	printf("Year: %d\n", m->year);
	printf("Rating: %s\n", m->rating);
	printf("Duration: %d:%d\n", m->duration/60,min(m->duration));
	printf("Genres: %s\n", m->genre);
	printf("Consumer rating: %.1f\n", m->c_rating);

}

const char* getMovieTitle(const Movie* mptr) {
	return mptr->title;
}
