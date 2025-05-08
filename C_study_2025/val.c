#include <stdio.h>
#include "val.h"

void demoFunction() {
	static int count = 0;
	count++;
	printf("count : %d\n", count);
}


void variable_and_print() {
	demoFunction();
	demoFunction();
	demoFunction();
	return 0;
}

void variable_and_reset() {
	int score1;
	int score2;

	score1 = 95;
	score2 = 80;

	printf("score1 : %d\n", score1);
	printf("score2 : %d\n", score2);
	return 0;
}

void student_score() {
	int std_num = 20180018;
	char grade;
	grade = 'A';
	float Kor_score = 95.6, Eng_score = 89.2;

	printf("student : %d\n", std_num);
	printf("score : %c\n", grade);
	printf("korean_score : %f\n", Kor_score);
	printf("English_score : %f\n", Eng_score);

	return 0;
}

void change_grade() {
	char grade = 'B';
	printf("score : %c\n", grade);

	grade = 'A';
	printf("changed score : %c\n", grade);

	return 0;
}

void exchange_data() {
	int a = 10;
	int b = 20;
	int tmp;
	printf("before change a : %d, before change b : %d\n", a, b);

	tmp = a;
	a = b;
	b = tmp;
	printf("after change a : %d, after change b : %d\n", a, b);
	
	return 0;
}

void size_of_data() {
	char a = 'a';
	int b = 123;
	double c = 123.456;

	printf("char size : %d bype\n", sizeof(char));
	printf("\n");

	printf("short size : %d bype\n", sizeof(short));
	printf("int size : %d bype\n", sizeof(int));
	printf("long size : %d bype\n", sizeof(long));
	printf("long long size : %d bype\n", sizeof(long long));
	printf("\n");

	printf("float size : %d bype\n", sizeof(float));
	printf("double size : %d bype\n", sizeof(double));
	printf("long double size : %d bype\n", sizeof(long double));
	printf("\n");

	printf("variable size\n");
	printf("char a size : %d bype\n", sizeof(a));
	printf("int 123 size : %d bype\n", sizeof(b));
	printf("double 123.456 size : %d bype\n", sizeof(c));
	printf("\n");

	return 0;
}