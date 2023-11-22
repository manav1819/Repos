/**
 *****************************************************************
 * Name: Manav Patel                                             *
 * Email: patmanav@sheridancollege.ca                            *
 * Student Id: 991500582                                         *
 * Date:                                                         *
 *                                                               *
 *****************************************************************
*/

#include <stdio.h>
#include "classList.h"
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

//Function that prints everything that is important. The heart of
void printReport(const char subjectCode[], const int studentNumbers[], const int marks[], int noOfStudents) {
	int width = 6, sum = 0;
	int highest = marks[0], lowest = marks[0];

	// Handling Exception: 
	if (noOfStudents == 0) {
		printf("There is a division by 0. Please rerun the program.\n");
		return;
	}

	printf("SUBJECT MARKS REPORT!\n");

	borders();

	printf("| %-18s|\n", subjectCode);
	middleLine();

	printf("|Row| Std No | Mark |\n");
	middleLine();

	for (int i = 0; i < noOfStudents; i++) {
		highest = MAX(marks[i], highest);
		lowest = MIN(marks[i], lowest);
		printf("| %2d| %-6.6d | %4d |\n",i+1, studentNumbers[i], marks[i]);
		sum += marks[i];

	}
	middleLine();
	printf("| Average    |  %3d |\n", sum / noOfStudents);
	printf("| Highest    |  %3d |\n", highest);
	printf("| Lowest     |  %3d |\n", lowest);
	borders();

}


// Function that prints this +-----------------+
void borders() {
	int i;
	for (i = 0; i < 21; i++)
	{
		printf("%c", (i == 0 || i == 20) ? '+' : '-');
	}
	printf("\n");
}

// Function that prints this +-----------+-----+
void middleLine() {
	int i;
	for (i = 0; i < 21; i++)
	{
		printf("%c", (i == 0 || i == 4|| i == 13 || i == 20) ? '+' : '-'); 
	}
	printf("\n");
}

