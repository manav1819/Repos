#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "marks.c"

static int getNoOfStudents(void);
static int getAverage(int NumberOfStudents);
static void printReport(int NumberOfStudents, int average);

int main(void) {
	int num;
	double average;
	printf("Class test marks report program...\n\n");

	num = getNoOfStudents();	
	average = getAverage(num);
	printReport(num, average);
	return 0;
}