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
#include <string.h>
#include "utils.h"

void printInWidth(const char str[], int width) {
	int i = 0;
	for (i = 0; i < width; i++) {
		if (i < strlen(str)) {
			printf("%c", str[i]);
		}
		else {
			printf(" ");
		}
	}
}

int min(int duration) {
	int minutes = 0;
	int hours = 0;
	hours = duration / 60;
	minutes = duration - (hours*60);
	return minutes;
}