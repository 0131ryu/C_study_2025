#include <stdio.h>
#include "exam7.h"

void find_even_num() {
	int i;
	int s[20];

	for (i = 0; i < 20; i++) {
		s[i] = i + 1;
	}

	for (i = 0; i < 20; i++) {
		if (s[i] % 2 == 0) {
			printf("s[%d] = %3d\n", i, s[i]);
		}
	}
	return 0;
}

void return_array() {
	int i;
	int arr[4] = { 10, 20, 30, 40 }; //int형 크기가 4인 배열 선언

	for (i = 0; i < 4; i++) {
		printf("arr[%d] = %3d", i, arr[i]); //배열 조회
		printf("\n");
	}
	return 0;
}

void return_two_layer_array() {
	int arr[3][3] = { {1, 2}, {3}, {4,5,6} };
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%3d", arr[i][j]); //C 언어에서 2차원 배열을 초기화할 때, 명시적으로 값을 할당하지 않은 요소는 0으로 자동 초기화 됨
		}
		printf("\n");
	}
	return 0;
}

void month_array() {
	int mon[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int a;

	printf("원하는 달을 입력하시오 : 종료 0, 입력 : ");
	scanf_s("%d", &a, sizeof(a));

	if (a == 0) {
		return 1;
	}

	for (int i = 1; i <= 12; i++) {
		if (a == i) {
			printf("%d월은 %d입니다.", a, mon[i - 1]);
			break;
		}
	}
	return 0;
}

void two_array_sum() {
	int a[3][3] = { {1, 2, 3}, {7, 8, 9}, {13, 14, 15} };
	int b[3][3] = { {4, 5, 6}, {10, 11, 12}, {16, 17, 18} };
	int c[3][3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d  ", a[i][j]);
		}
		printf("\n");
	}
	printf(" +  \n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d  ", b[i][j]);
		}
		printf("\n");
	}
	printf(" =  \n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			c[i][j] = a[i][j] + b[i][j];
			printf("%d  ", c[i][j]);
		}
		printf("\n");
	}
	return 0;
}