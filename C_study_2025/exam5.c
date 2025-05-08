#include <stdio.h>
#include "exam5.h"

void find_max_value() {
	int a, b, max;

	printf("input 2 int values : ");
	scanf_s("%d %d", &a, &b); //, 넣으면 입력도 ,가 들어가야 함

	if (a > b)
		max = a;
	else
		max = b;

	printf("max value is %d", max);
	return 0;
}

void input_value() {
	int x = 0;

	printf("input three values : ");
	scanf_s("%d", &x, sizeof(x)); // 정수형 입력 시 sizeof(x)를 버퍼 크기로 전달

	switch (x) {
		case 0: 
			printf("zero\n"); break;
		case 1:
			printf("one\n"); break;
		case 2:
			printf("two\n"); break;
		default:
			printf("others\n");
	}
	return 0;
}

void switch_score() {
	int jumsu;
	char grade;

	printf("input score : ");
	scanf_s("%d", &jumsu, sizeof(jumsu));

	if (jumsu >= 90)
		grade = 'A';
	else if (jumsu >= 80)
		grade = 'B';
	else if (jumsu >= 70)
		grade = 'C';
	else if (jumsu >= 60)
		grade = 'D';
	else
		grade = 'F';

	printf("Your score %d is %c grade.", jumsu, grade);

	return 0;
}

void favorite_fruit() {
	int fruit;

	printf("input your favorite fruit number :");
	scanf_s("%d", &fruit, sizeof(fruit));

	switch (fruit) {
	case 1:
		printf("Your favorite fruit is apple.");
		break;
	case 2:
		printf("Your favorite fruit is pear.");
		break;
	case 3:
		printf("Your favorite fruit is watermelon.");
		break;
	default:
		printf("there is no fruit what you like.");
	}
	return 0;
}

void man_or_woman() {
	int check_gender;
	const char *result;

	printf("check your gender, input number : ");
	scanf_s("%d", &check_gender, sizeof(check_gender));

	if (check_gender == 1)
		result = "man";
	else if (check_gender == 2)
		result = "woman";
	else
		result = "wrong input. try again";

	printf("You are %s", result);

	return 0;
}

void find_max_value_from_three() {
	int a, b, c, max;

	printf("input three int values : ");
	scanf_s("%d %d %d", &a, &b, &c);

	max = a;
	if (max < b)
		max = b;
	
	if (max < c)
		max = c;
	
	printf("max int value is %d", max);
	return 0;
}

void find_year_emblem() {
	int year;
	const char* result;

	printf("What year were you born? : ");
	scanf_s("%d", &year, sizeof(year));

	if (year == 0) {
		printf("wrong input, try again.\n");
		return 1;
	}

	//year %= year; 이러면 바로 오류남
	int remainder = year % 12;

	switch (remainder) {
	case 0:
		result = "monkey";
		break;
	case 1:
		result = "chicken";
		break;
	case 2:
		result = "dog";
		break;
	case 3:
		result = "pig";
		break;
	case 4:
		result = "rat";
		break;
	case 5:
		result = "ox";
		break;
	case 6:
		result = "tiger";
		break;
	case 7:
		result = "rabbit";
		break;
	case 8:
		result = "dragon";
		break;
	case 9:
		result = "snake";
		break;
	case 10:
		result = "horse";
		break;
	case 11:
		result = "sheep";
		break;
	default:
		result = "others";
	}

	printf("result : %s\n", result); // %s로 문자열 전체 출력

	return 0;
}

void mutiple_two_value() {
	int a, b;
	const char* result;

	printf("input two int vaules : ");
	scanf_s("%d %d", &a, &b);

	if (a == 0 || b == 0) {
		printf("wrong input, try again.");
		return 1;
	}

	if (a * b < 0) {
		result = "The product of two integers is negative";
	}
	else {
		result = "The product of two integers is positive";
	}

	printf("%s", result);

	return 0;
}

void check_bmi() {
	int weight, height;
	const char* result; // result 초기화

	printf("Input your weight : ");
	scanf_s("%d", &weight, sizeof(weight));

	printf("Input your height : ");
	scanf_s("%d", &height, sizeof(height));

	float height_m = (float)height / 100.0f;
	float bmi = (float)weight / (height_m * height_m);

	if (bmi < 20) {
		result = "underweight";
	}
	else if (bmi >= 20 && bmi <= 24) {
		result = "normal weight";
	}
	else if (bmi >= 25 && bmi <= 30) {
		result = "mild obesity";
	}
	else if (bmi > 30) {
		result = "Obesity";
	}
	else {
		result = "nothing";
	}

	printf("%s", result);
	return 0;
}

void bus_fee() {
	int division;
	const char* result = "undefined";
	const char* cost = "undefined";

	printf("Input number ( 1 - adult, 2 - teenager, 3 - children) : ");
	scanf_s("%d", &division, sizeof(division));

	if (division == 1) {
		result = "adult";
		cost = "1400won";
	}
	else if (division == 2) {
		result = "teenager";
		cost = "1000won";
	}
	else if (division == 3) {
		result = "children";
		cost == "500won";
	}

	printf("You are %s, your cost is %s", result, cost);
	return 0;
}