#include <stdio.h>
#include "exam8.h"

int sum(int x, int y) {
	return x + y;
}

void return_sum(void) {
	int x, y;
	printf("�� ���� �Է��Ͻÿ�");
	scanf_s("%d %d", &x, &y);
	printf("�� ���� ���� = %d", sum(x, y));

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
	printf("�� ���� �Է��Ͻÿ�.");
	scanf_s("%d %d", &a, &b);
	result = even(a, b);

	if (result == 0) {
		printf("�Է��� �� ���� ¦���� �ƴϴ�.");
	}
	else {
		printf("�Է��� �� ���� ��� ¦���̴�.");
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
	printf("�� ���� �Է��Ͻÿ�");
	scanf_s("%d", &dan);
	gugudan(dan);
	return 0;
}