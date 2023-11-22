#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include "marks.c"

int getNoOfStudents(void);
int getAverage(int NumberOfStudents);
void printReport(int NumberOfStudents, int average);

int main(void) {
	int num;
	double average;
	printf("Class test marks report program...\n\n");

	num = getNoOfStudents();	
	average = getAverage(num);
	printReport(num, average);
	return 0;
}