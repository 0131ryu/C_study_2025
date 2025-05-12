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
	int arr[4] = { 10, 20, 30, 40 }; //int�� ũ�Ⱑ 4�� �迭 ����

	for (i = 0; i < 4; i++) {
		printf("arr[%d] = %3d", i, arr[i]); //�迭 ��ȸ
		printf("\n");
	}
	return 0;
}

void return_two_layer_array() {
	int arr[3][3] = { {1, 2}, {3}, {4,5,6} };
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%3d", arr[i][j]); //C ���� 2���� �迭�� �ʱ�ȭ�� ��, ��������� ���� �Ҵ����� ���� ��Ҵ� 0���� �ڵ� �ʱ�ȭ ��
		}
		printf("\n");
	}
	return 0;
}

void month_array() {
	int mon[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int a;

	printf("���ϴ� ���� �Է��Ͻÿ� : ���� 0, �Է� : ");
	scanf_s("%d", &a, sizeof(a));

	if (a == 0) {
		return 1;
	}

	for (int i = 1; i <= 12; i++) {
		if (a == i) {
			printf("%d���� %d�Դϴ�.", a, mon[i - 1]);
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