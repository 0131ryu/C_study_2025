#include <stdio.h>
#include "exam8.h"

int sum(int x, int y) {
	return x + y;
}

void return_sum(void) {
	int x, y;
	printf("두 수를 입력하시오");
	scanf_s("%d %d", &x, &y);
	printf("두 수의 합은 = %d", sum(x, y));

	return 0;
}


int even(int a, int b) {

	if (a % 2 == 0 && b % 2 == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void correct_even_num(void) {
	int a, b, result;
	printf("두 수를 입력하시오.");
	scanf_s("%d %d", &a, &b);
	result = even(a, b);

	if (result == 0) {
		printf("입력한 두 수는 짝수가 아니다.");
	}
	else {
		printf("입력한 두 수는 모두 짝수이다.");
	}
	return 0;
}

void gugudan(int i) {
	for(int j = 1; j < 10; j++) {
		printf("%d + %d = %d\n", i, j, i * j);
	}
}

void multiplication_table(void) {
	int dan;
	printf("단 값을 입력하시오");
	scanf_s("%d", &dan);
	gugudan(dan);
	return 0;
}