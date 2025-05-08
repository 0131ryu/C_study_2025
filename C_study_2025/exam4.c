#include <stdio.h>
#include "exam4.h"

void calculate_minus() {

	int a = 5;
	int b = 5;
	printf("%d %d\n", a--, --b);
	printf("%d %d\n", a--, --b);
	printf("%d %d\n", a--, --b);
	printf("%d %d\n", a--, --b);
	printf("%d %d\n", a--, --b);

	return 0;
}

void four_calculate() {
	int x = 10, y = 4, r = 6;
	double pi = 3.141592;
	printf("x + y / x * y = %d\n", x + y / x * y);
	printf("(x + y) / x * y = %d\n", (x + y) / x * y);
	printf("(x + y * r) / 2 = %d\n", (x + y * r) / 2);
	printf("(x + y + r) % 2 = %d\n", (x + y + r) % 2);
	printf("pi * r * r = %f\n", pi * r * r);
	
	return 0;	
}

void priority_result() {

	int a = 10, b = 20, c = 30, d = 5;
	int result;

	result = a + b * c / d;
	printf("result : %d\n", result);
	result = (a + b) * c / d;
	printf("result : %d\n", result);
	result = a + b * c % d;
	printf("result : %d\n", result);
	result = (a + b) * c % d;
	printf("result : %d\n", result);
	result = a = b = 1;
	printf("result : %d\n", result);
	return 0;
}

void choose_max_value() {
	int x, y, z, max;
	printf("choose int variable value : ");
	scanf_s("%d %d %d", &x, &y, &z, 1);
	printf("x : %d, y : %d, z : %d\n", x, y, z);

	max = (x > y ? x : y);
	max = (max > z ? max : z);

	printf("Max value : %d\n", max);
	return 0;
}