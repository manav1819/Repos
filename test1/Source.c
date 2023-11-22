#define SECURE_CRT_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, b, c, d, e;
	a = 109; b = 105; c = 328; d = 56;
	e = calc(a, b, c, d);
	printf(" %d %d %d %d", a, b, c, d);
	return 1;
}
int calc(int a1, int b1, int c1, int d1)
{
	int result, temp;
	temp = a1 * b1;
	result = temp - c1 + d1;
	return result;
}
