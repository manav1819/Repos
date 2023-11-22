/*
 *****************************************************************
 * Name: Manav Patel                                             *
 * Email: patmanav@sheridancollege.ca                            *
 * Student Id: 991500582                                         *
 * Date: 23-09-2023                                              *
 *                                                               *
 *****************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "classList.h"
#include "utils.h"
const char nos[] = "Number of Students";
const char SN[] = "Student Number";
const char Marks[] = "Marks";


int main() {

    //int stno[4] = {12345, 23456, 345678, 45678};
    //int mark[4] = {55, 66, 44, 88};
    //printReport("PROG36859", stno, mark, 4);

    printf("Enter subject Name:");
    char subName[10];
    (void)scanf("%s", &subName);

    printf("Enter the number of students (max 50): ");
    int noOfStds = getMMInt(1,50,nos);
    //(void)scanf("%d", &noOfStds);

    printf("Enter %d student numbers and marks...\n", noOfStds);
    int stdNum[50];
    int marks[50];

    for (int i = 0; i < noOfStds; i++) {
        printf("%d:\n", i + 1);
        
        printf("Student Number: ");
        stdNum[i]= getMMInt(10000, 999999, SN);
        //(void)scanf("%d", &stdNum[i]);
        
        
        printf("Mark: ");
        marks[i]= getMMInt(0, 100, Marks);
        //(void)scanf("%d", &marks[i]);
    }

    printReport(subName, stdNum, marks, noOfStds);


    return 0;
}