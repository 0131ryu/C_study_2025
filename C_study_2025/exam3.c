#include <stdio.h>
#include "exam3.h"

void find_error_variable(void) {
	//int 2018_Num; //����
	int num_2018 = 2018;
	// char univ#; //����
	char univ = '0';
	char dept_num =  '0';
	int for1 = 0;
	char ch = 'C'; //"" �� �ѵ�

	printf("%c\n", dept_num);

	int stud_num = 20;

	return 0;

}

void print_result(void) {
	printf("%d / %d = %.1f\n", 15, 2, 7.5);
	
	return 0;
}

void print_result_float(void) {
	float a = 314.1592;
	printf("%8.2f\n", a);
	return 0;
}

void exchange_variables(void) {
	int x = 123;
	int y = 456;
	int z;

	z = y;
	y = x;
	x = z;

	printf("%d %d %d\n", x, y, z);

	return 0;
}

void variables_result(void) {
	short a = 32768;
	int b = 8;
	double c = 1.234;
	char d = 'D';

	printf("%d, %o, %d, %d\n", a, b, sizeof(c), d);

	return 0;
}

void exchane_alphbet_num(void) {
	unsigned char alpha; //�Է¹޴� ��
	printf("alphabet input : ");
	scanf_s("%c", &alpha, 1); //����ڷκ��� ���� : printf�� �ƴ� scanf
	//scanf_s�� ���� �����÷ο츦 �����ϱ� ���� �߰����� ����(����ũ��) �䱸��

	printf("The decimal number of the alphabet %c is %d\n", alpha, alpha);

	return 0;
}