#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct Student {
	char name[81];
	int stno;
	double gpa;
};

void prnStds(const struct Student a[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("-%3d- %s: %d[%.1lf]\n",(i+1),a[i].name, a[i].stno, a[i].gpa);
	}
}

int readStd(struct Student* s, FILE* f) {
	int res = fscanf(f, "%80[^,],%d,%lf", s->name, &s->stno, &s->gpa)==3;
	while (res && fgetc(f) != '\n');
	return res;
}

int main(void) {
	struct Student s[50];
	int noOfStd;
	FILE* fptr;
		fptr = fopen("/Resources Files/students.csv", "r");
	for (noOfStd = 0; readStd(&s[2], fptr); noOfStd++);
	prnStds(&s, noOfStd);
	fclose(fptr);
	return 0;
}