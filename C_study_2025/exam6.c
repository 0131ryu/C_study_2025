#include <stdio.h>
#include "exam6.h"

void ascii_codes() {
	int i;
	int count = 0;
	
	for (int i = 65; i <= 127; i++) {
		printf("%c ", i);
		count++;

		//8개 출력하면 줄 바꿈
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

	printf("\n최종 합계: 1 + 3 + ...... + 99 = %d\n", hap); 
	// 루프 종료 후 최종 합계 출력

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
		printf("나무를 %d번 찍었다.\n", i);
	}
	return 0;
}

void divisor_for() {
	int i = 1;
	int num;

	printf("1 이상의 정수를 입력하시오 : ");
	scanf_s("%d", &num, sizeof(num));

	if (num < 1) {
		printf("오류입니다.");
		return 1;
	}

	printf("%d의 약수\n", num);
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
		printf("누적 %d = %d\n", su, hap);
		su = su + 2; //다음 짝수로 증가
	}

	printf("\n1부터 1000까지의 짝수의 합 =  %d\n", hap);
	// 루프 종료 후 최종 합계 출력

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

	printf("숫자를 입력하세요 : ");
	scanf_s("%d", &num);

	for (int i = 0; i < num; i++) {
		printf("4차 산업 혁명\n");
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