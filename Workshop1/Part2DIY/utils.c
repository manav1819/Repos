#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

void clear(void);

int getInt(void) {
	int x;
	int rc;
	bool flag = true;
	char afterValue;
	int counter=0;

	while (flag)
	{
		if (counter != 0) {
			printf("Enter an integer value:");
		}
		rc = scanf("%d%c", &x, &afterValue);

		if (rc == 0) {
			printf("\nYou have entered a character/ invalid input...\n");
			clear();
		}
		else if (afterValue != '\n') {
			printf("\nYou have entered an invalid input or its a double/ float\n");
			clear();
		}
	
		else
			flag = false;
		counter++;
	}

	return x;
}

void clear(void) {

	while (getchar() != '\n');
}

int getIntMM(int min, int max) {

	int value, rc, flag = 1;
	char afterValue;
	int counter=0;

	while (flag)
	{
		if (counter != 0) {
			printf("\nEnter a valid integer value in the range[%d, %d]:", min, max);
		}
		rc = scanf("%d%c", &value, &afterValue);

		if (rc == 0) {
			printf("\nYou have entered a character/ invalid input...\n");
			clear();
		}
		else if (afterValue != '\n') {
			printf("\nYou have entered an invalid input or its a double/ float\n");
			clear();
		}

		else if (value < min || value > max) {
		printf("\nThe value entered in not in the provided range\n");
		}
		else
			flag = 0;
		counter++;
	}
	return value;

}




double getDouble(void) {
	double x;
	int rc;
	bool flag = true;
	char afterValue;
	int counter = 0;

	while (flag)
	{
		if (counter != 0) {
			printf("Enter a double value:");
		}
		rc = scanf("%lf%c", &x, &afterValue);

		if (rc == 0) {
			printf("\nYou have entered a character/ invalid input...\n");
			clear();
		}
		else if (afterValue != '\n') {
			printf("\nYou have entered an invalid input float\n");
			clear();
		}

		else
			flag = false;
		counter++;
	}

	return x;
}

double getDoubleMM(double min, double max) {

	double value;
	int rc, flag = 1;
	char afterValue;
	int counter = 0;

	while (flag)
	{
		if (counter != 0) {
			printf("\nEnter a valid double value in the range[%.1lf, %.1lf]:", min, max);
		}
		rc = scanf("%lf%c", &value, &afterValue);

		if (rc == 0) {
			printf("\nYou have entered a character/ invalid input...\n");
			clear();
		}
		else if (afterValue != '\n') {
			printf("\nYou have entered an invalid input or its a float\n");
			clear();
		}

		else if (value < min || value > max) {
			printf("\nThe value entered in not in the provided range\n");
		}
		else
			flag = 0;
		counter++;
	}
	return value;

}


void line(char fill, int len) {
	int i;
	for (i = 0; i < len; i++) {
		printf("%c", fill);
	}
	printf("\n");
}