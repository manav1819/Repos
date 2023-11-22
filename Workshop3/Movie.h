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
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <stdio.h>

typedef struct{
	char title[61];
	int year;
	char rating[3];
	int duration;
	char genre[60];
	float c_rating;

}Movie;
int loadMovie(struct Movie* mptr, FILE* fptr);
void list(const struct Movie* mptr, int row);
void display(const Movie* m);
const char* getMovieTitle(const Movie* mptr);

#endif // !SDDS_MOVIE_H

