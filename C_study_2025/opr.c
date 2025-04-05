#include <stdio.h>
#include "opr.h"

void operation_and_print(void) {
	int a = 10, b = 3;
	printf("plus : %d\n", a + b);
	printf("division : %d\n", a / b);
	printf("exc : %d\n", a % b); 
	return 0;
}

void logical_operation_and_print(void) {
	int x = 5, y = 3;
	printf("x > y && y < 10 : %d\n", (x > y && y < 10));
	printf("x < y || x > 0 : %d\n", (x < y || x > 0));
	printf("!x : %d\n", !x);
	return 0;
}

void bit_operation_and_print(void) {
	int x = 5, y = 3;
	printf("x & y : %d\n", x & y);
	printf("x | y : %d\n", x | y);
	printf("x ^ y : %d\n", x ^ y);
	printf("~x : %d\n", ~x);
	printf("x << 1 : %d\n", x << 1);
	printf("x <<<>> 1 : %d\n", x >> 1);
	return 0;
}

void compound_operation_and_print(void) {
	int a = 10;
	a += 5;
	printf("a += 5 : %d\n", a);
	a *= 2;
	printf("a *= 2 : %d\n", a);
	return 0;
}

void priority_operation_and_print(void) {
	int result = 5 + 3 * 2;
	printf("result : %d\n", result);
	return 0;
}