#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "utils.h"

// This function validates the integer.
int getInt(char Name[]) {
    int x;
    int rc;
    char afterValue;
    int counter = 0;
    int flag = 1;
    while (flag)
    {
        if (counter != 0) {   
            printf("Enter an integer value for %s:",Name); // This is to make sure that this statement print after the 1st time the while loop runs
        }
        rc = scanf("%d%c", &x, &afterValue);

        if (rc == 0 || afterValue != '\n') {
            printf("\nInvalid Integer, try again: \n");
            flushKey();
        }

        else {
            flag = 0;
        }
        counter++;
    }
    return x;
}


int getMMInt(int min, int max, const char valueName[]) {
    int value=0, flag = 0;
    char afterValue;
    
    while (!flag) {
        start: value = getInt(valueName);

        //Print this if the integer is not in range.
        if (value < min || value > max) {
            printf("[%d <= %s <= %d], try again: ", min, valueName, max);
            goto start;
        }
        else {
            flag = 1;
        }
    }
    return value;
}


// This function clears the buffer.
void flushKey(void) {
    char ch = 'x';
    while (ch != '\n') {
        ch = getchar();
    }
}

