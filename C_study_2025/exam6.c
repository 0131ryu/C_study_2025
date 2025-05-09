#include <stdio.h>
#include "exam6.h"

void ascii_codes() {
	int i;
	int count = 0;
	
	for (int i = 65; i <= 127; i++) {
		printf("%c ", i);
		count++;

		//8�� ����ϸ� �� �ٲ�
		if (count % 8 == 0) {
			printf("\n");
		}
	}
	printf("\n");

	return 0;
}

void plus_odd_number() {
	int su = 1;
	int hap = 0;

	for (int i = 1; su < 100; i++) {
		hap = hap + su;
		printf("1 + 3 + ...... + %d = %d\n", su, hap);
		su = su + 2;
	}

	printf("\n���� �հ�: 1 + 3 + ...... + 99 = %d\n", hap); 
	// ���� ���� �� ���� �հ� ���

	return 0;
}

void twin_for() {
	int i = 0;
	int j = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j <= i; j++) {
			printf("&"); //i = 0 -> j = 0,  i = 1 -> j = 0, 1, i = 2 -> j = 0, 1, 2
		}
		printf("\n");
	}
	return 0;
}

void try_tree_10times() {
	int num = 1;

	for (int i = 1; i <= 10; i++) {
		//i = i + 1;
		printf("������ %d�� �����.\n", i);
	}
	return 0;
}

void divisor_for() {
	int i = 1;
	int num;

	printf("1 �̻��� ������ �Է��Ͻÿ� : ");
	scanf_s("%d", &num, sizeof(num));

	if (num < 1) {
		printf("�����Դϴ�.");
		return 1;
	}

	printf("%d�� ���\n", num);
	for (int i = 1; i <= num; i++) {
		if (num % i == 0) {
			printf("%d\n", i);
		}
	}
	return 0;
}

void plus_even_number() {
	int su = 2;
	int hap = 0;

	for (int i = 1; su <= 1000; i++) {
		hap = hap + su;
		printf("���� %d = %d\n", su, hap);
		su = su + 2; //���� ¦���� ����
	}

	printf("\n1���� 1000������ ¦���� �� =  %d\n", hap);
	// ���� ���� �� ���� �հ� ���

	return 0;
}

void reverse_star() {
	for (int i = 5; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

void multiple_of_five() {
	int i = 1;
	
	for (int i = 1; i <= 100; i++) {
		i = i + 4;
		printf("%d ", i);
	}
	return 0;
}

void show_count_word() {
	int i = 0;
	int num;

	printf("���ڸ� �Է��ϼ��� : ");
	scanf_s("%d", &num);

	for (int i = 0; i < num; i++) {
		printf("4�� ��� ����\n");
	}
	return 0;
}

void minus_result() {

	for (int i = 5; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			printf("%d", j);
		}
		printf("\n");
	}
	return 0;
}

void minus_result_ver2() {

	for (int i = 5; i >= 0; i--) {
		for (int j = i; j >= 0; j--) {
			printf("%d", j);
		}
		printf("\n");
	}
	return 0;
}