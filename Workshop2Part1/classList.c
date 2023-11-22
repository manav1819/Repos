/**
 *****************************************************************
 * Name: Manav Patel                                             *
 * Email: patmanav@sheridancollege.ca                            *
 * Student Id: 991500582                                         *
 * Date: 25-09-2023                                              *
 *                                                               *
 *****************************************************************
*/

#include <stdio.h>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

//Function that prints everything that is important. The heart of
void printReport(const char subjectCode[], const int studentNumbers[], const int marks[], int noOfStudents) {
	int width = 6, sum = 0;
	int highest = marks[0], lowest = marks[0];
	printf("SUBJECT MARKS REPORT!\n");

	borders();

	printf("|%s      |\n", subjectCode);
	middleLine();

	printf("| Std No | mark |\n");
	middleLine();

	for (int i = 0; i < noOfStudents; i++) {
		highest = MAX(marks[i], highest);
		lowest = MIN(marks[i], lowest);
		printf("| %.6d |   %d |\n", studentNumbers[i], marks[i]);
		sum += marks[i];

	}
	middleLine();
	printf("|Average |   %d |\n", sum / noOfStudents);
	printf("|Highest |   %d |\n", highest);
	printf("|Lowest  |   %d |\n", lowest);
	middleLine();

	return 0;
}

// Function that prints this +-----------------+
borders() {
	int i;
	for (i = 0; i < 17; i++)
	{
		printf("%c", (i == 0 || i == 16) ? '+' : '-');
	}
	printf("\n");
}

// Function that prints this +-----------+-----+
middleLine() {
	int i;
	for (i = 0; i < 17; i++)
	{
		printf("%c", (i == 0 || i == 9 || i == 16) ? '+' : '-');
	}
	printf("\n");
}
