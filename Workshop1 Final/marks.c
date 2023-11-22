#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#define maxNoOfStudents 250

int getNoOfStudents(void) {
	printf("\nPlease enter the total number of students inside your class:");
	int noOfStudents;
	int n = scanf("%d", &noOfStudents);
	return noOfStudents;
}

int getAverage(int NumberOfStudents) {
	int sum = 0, i;
	int marks[maxNoOfStudents];
	int avg;
	printf("Enter the Marks for %d Student.\n", NumberOfStudents);
	for (i = 0; i < NumberOfStudents; i++) {
		check: printf("Enter the Marks for Student %d: ", i + 1);
		scanf("%d", &marks[i]);
		
		//Check if the input is more than 100
		if (marks[i] > 100) {
			printf("Invalid Mark. The marks should be less than 100.\n");
			goto check;
		}

		//Check if the input is Negative
		else if (marks[i] < 0) {
			printf("Invalid Mark. The marks cannot be negative.\n");
			goto check;
		}

		sum += marks[i]; //Adding all the marks together

	}
	avg = sum / NumberOfStudents;
	return avg;
}

void printReport(int NumberOfStudents, int average) {
	
	printf("\nNo of Students: %d",NumberOfStudents);
	if (average<50) {
		printf("Class Average: %d%% <F>",average);
	}
	else if (average >= 50 && average < 55) {
		printf("Class Average: %d%% <D>", average);
	}
	else if (average >= 55 && average < 60) {
		printf("Class Average: %d%% <D+>", average);
	}
	else if (average >= 60 && average < 65) {
		printf("Class Average: %d%% <C>", average);
	}
	else if (average >= 65 && average < 70) {
		printf("Class Average: %d%% <C+>", average);
	}
	else if (average >= 70 && average < 75) {
		printf("Class Average: %d%% <B>", average);
	}
	else if (average >= 75 && average < 80) {
		printf("Class Average: %d%% <B+>", average);
	}
	else if (average >= 80 && average < 90) {
		printf("Class Average: %d%% <A>", average);
	}
	else if (average >= 90 && average <= 100) {
		printf("Class Average: %d%% <A+>", average);
	}
	
}