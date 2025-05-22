#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "hello.h"

int hello_world() { //�Լ�, int�� �Լ��� Ÿ��
	printf("hello, World!\n"); //����(��)��, ������ �ǹ�
	return 0; //��ȯ ��

	//���ڿ� = ����(�迭) char[15] 
	//���ڿ��� ù���ڷ� �迭�� �ּҸ� �ľ��� = �迭�� �̸�
}

void string_input_output() {
	char ch = 0; //���� ���� + ����
	ch = getchar(); //�� ���ڸ� ����
	putchar(ch);
	putchar('Z');
	
	return 0;
}

void string_input_output_non_buffered() {
	char ch = 0;
	printf("�ƹ� Ű�� ������ �������� �Ѿ�ϴ�.\n");

	ch = _getch();
	
	printf("�Է��� Ű�� ");
	putchar(ch);
	printf("�Դϴ�.");
	return 0;
}

void example_string_array() {
	char szName[32] = { 0 };
    printf("�̸��� �Է��ϼ���: ");

    if (fgets(szName, sizeof(szName), stdin)) { //szName �ּ� ����
        // ���� ���� ����
        szName[strcspn(szName, "\n")] = 0;
    }

    printf("����� �̸��� ");
    puts(szName);
    printf("�Դϴ�.\n");

    return 0;
}

void form_char(void) {
	int x = 10;

	putchar('B');
	putchar('\n');
	printf("%c\n", 65); //A

	printf("x�� %d�Դϴ�\n\a", x);
	
	printf("%d\n", 1234);
	printf("%d, %d\n", 1234, -5678);
	printf("%+d, %+d\n", 1234, -5678);

	printf("%8d\n", 1234);
	printf("%08d\n", 1234);
	return 0;
}

void write_szBuffer(void) {
	char szBuffer[4] = { 0 };
	scanf_s("%4c", szBuffer, _countof(szBuffer));
	printf("%c%c%c%c\n", szBuffer[0], szBuffer[1], szBuffer[2], szBuffer[3]);
	return 0;
}

void what_is_your_info() {
	char szName[32] = { 0 };
	int nAge = 0;

	printf("���̸� �Է��ϼ���. : ");
	scanf_s("%d%*c", &nAge); // %*c = \n�� ������

	printf("�̸��� �Է��ϼ���. : ");
	gets_s(szName, sizeof(szName));

	printf("%d�� %s\n", nAge, szName);

	return 0;
}

void szBuffer_left_right() {
	char szBuffer[32] = { 0 };

	//����ڰ� �Է��� ���ڿ��� �迭�� �����ϰ� ���
	scanf_s("%s", szBuffer, (unsigned)_countof(szBuffer));
	printf("%s\n", szBuffer);

	char szBufferLeft[32] = { 0 };
	char szBufferRight[32] = { 0 };

	scanf_s("%s%s", 
		szBufferLeft, (unsigned)_countof(szBufferLeft),
		szBufferRight, (unsigned)_countof(szBufferRight));
	scanf_s("%s %s \n", szBufferLeft, szBufferRight);
}

void find_your_info() {
	char szName[20] = { 0 };
	int szAge = 0;

	printf("���̸� �Է��ϼ���: ");
	scanf_s("%d%*c", &szAge);

	printf("�̸��� �Է��ϼ���: ");
	gets_s(szName, sizeof(szName));

	printf("����� ���̴� %d���̰� �̸��� '%s'�Դϴ�.", szAge, szName);
	return 0;
}

void two_int_result_double() {
	int a = 0, b = 0;
	double result = 0;

	printf("�� ������ �Է��ϼ���. : ");
	scanf_s("%d%d", &a, &b);
	result = (double) (a + b) / 2;
	printf("AVG: %.2f", result);
	return 0;
}

void transfer_time() {
	int time = 0;
	int hour = 0, minute = 0, second = 0;

	scanf_s("%d", &time);
	hour = time / 3600;
	minute = (time % 3600) / 60;
	second = time % 60;

	printf("%d�ʴ� %02d�ð� %02d�� %02d���Դϴ�.",
		time, hour, minute, second);
	return 0;

}

void change_two_int() {
	int a = 0, b = 0, tmp = 0;

	scanf_s("%d%d", &a, &b);

	tmp = a;
	a = b;
	b = tmp;

	printf("a: %d, b: %d", a, b);
	return 0;
}

void accumulate_sum() {
	int input = 0, total = 0;

	scanf_s("%d", &input);
	total += input;
	scanf_s("%d", &input);
	total += input;
	scanf_s("%d", &input);
	total += input;
	printf("Total : %d", total);
	return 0;
}

void minus_use_bit_operator() {
	int a = 0, b = 0;
	int result = 0;
	scanf_s("%d%d", &a, &b);

	result = a + (~b + 1); // a- b�� ����, ���� �̿�

	printf("%d", result);
	return 0;
}

void acceptance_or_failure() {
	int score = 0;

	printf("������ �Է��ϼ��� : ");
	scanf_s("%d", &score);

	printf("%s", score >= 80 ? "�հ�" : "���հ�");

	return 0;
}

void show_max_value() {
	int input = 0;
	int max = 0;
	
	scanf_s("%d%*c", &input);
	max = input;
	scanf_s("%d%*c", &input);
	max = (max > input) ? max : input;
	scanf_s("%d%*c", &input);
	max = (max > input) ? max : input;
	printf("MAX : %d", max);
	return 0;
}

void show_max_value_all() {
	int a = 0, b = 0, c = 0;
	int max = 0;
	
	scanf_s("%d%d%d", &a, &b, &c);

	max = (a > b) ? a : b;
	max = (c > max) ? c : max;
	printf("MAX : %d", max);
	return 0;
}

void show_max_value_use_if() {
	int input = 0, max = 0;

	scanf_s("%d", &input);
	max = input;
	scanf_s("%d", &input);
	if (max < input) {
		max = input;
	}
	scanf_s("%d", &input);
	if (max < input) {
		max = input;
	}
	printf("MAX: %d", max);
	return 0;
}

void what_is_bus_fare() {
	int bus_fare = 750;
	int age = 0;

	scanf_s("%d", &age);
	if (age >= 20) {
		age = 20;
		bus_fare = 1000;
	}

	printf("���� : %d, �������: %d��", age, bus_fare);
	return 0;
}

void age_differential_bus_fare() {
	int age = 0;
	double rate = 0.0;
	scanf_s("%d", &age);
	if (age < 14) 
		if (age < 4) 
			rate = 0.0;
		else 
			rate = 0.5;
	else 
		if (age >= 20) 
			rate = 1.0;
		else 
			rate = 0.75;
	

	double fee = 1000 * rate;
	printf("����� %d��", (int)fee);
	return 0;
}

void show_star_number() {
	int input = 0, i = 0;

	scanf_s("%d", &input);

	while (input < 1 || input > 9) {
		puts("1~9 ������ ���� �Է� �ٶ��ϴ�.");
		return 0;
	}

	while (i < input) {
		printf("*\t");
		++i;
	}

	return 0;
}

void show_sum_one_to_ten() {
	int cnt = 0;
	int result = 0;

	while (cnt < 11) {
		for (int i = 1; i <= 10; i++) {
			cnt += i;
			result += i;
		}
		printf("Total : %d", result);
	}

	return 0;
}

void five_multiple_five() {
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			printf("*\t");
		}
		printf("\n");
	}
	return 0;
}

void triangle_five_star() {
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= i; j++) {
			printf("*\t");
		}
		printf("\n");
	}
	return 0;
}

void opposite_triangle_five_star() {
	for (int i = 0; i < 5; ++i)
	{ 
		for (int j = 0; j < 5; ++j)
		{
			if (j >= 4 - i)
				printf("* ");
			else
				printf("  ");
		}
		putchar('\n');
	}
	return 0;
}

void tree_triangle() {
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5 + i; ++j)
		{
			if (j >= 4 - i)
				printf("* ");
			else
				printf("  ");
		}
		putchar('\n');
	}
	return 0;
}

void find_array_max() {
	int intArray[5] = { 50, 40, 10, 50, 20 };
	int nMax = 0;

	nMax = intArray[0];

	for (int i = 0; i < 5; i++) {
		if (intArray[i] > nMax) {
			nMax = intArray[i];
		}
	}
	printf("MAX: %d", nMax);
	return 0;
}

void find_array_min() {
	int intArray[5] = { 50, 40, 10, 50, 20 };
	int nMin = 0;

	for (int i = 0; i < 5; i++) {
			if (intArray[0] > intArray[i]) {
				//nMin = intArray[i];

				int tmp = intArray[0];
				intArray[0] = intArray[i];
				intArray[i] = tmp;
		}
	}
	printf("MIN: %d", intArray[0]);

	return 0;
}

void bubble_sort() {
	int aList[5] = { 30, 40, 10, 50, 20 };

	for (int j = 0; j < 4; j++) {
		for (int i = j+1; i < 5; i++) {
			if (aList[j] > aList[i]) {
				int tmp = aList[j];
				aList[j] = aList[i];
				aList[i] = tmp;
			}
		}

		for (int i = 0; i < 5; i++) {
			printf("%d ", aList[i]);
		}
		printf("\n");
	}
	
	return 0;
}

void sort_selection() {
	int aList[6] = {30, 50, 10, 20, 40, 70};
	int idx = 0;

	for (int i = 0; i < 5; i++) {
		idx = i;
		for (int j = i + 1; j < 6; j++) {
			if (aList[idx] > aList[j]) {
				idx = j;
			}
		}
		if (idx != i) {
			int tmp = aList[i];
			aList[i] = aList[idx];
			aList[idx] = tmp;
		}
	}

	for (int i = 0; i < 5; i++) {
		printf("%d ", aList[i]);
	}

	return 0;
}

void show_five_to_five() {
	
	int aList[5][5] = { 0 };
	int sum = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i % 2 == 0) {
				aList[i][j] = ++sum;
			}
			else {
				aList[i][4-j] = ++sum;
			}
			
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d ", aList[i][j]);
		}
		printf("\n");
	}

	return 0;
}

void snail_arrangement() {
	int aList[5][5] = { 0 };
	int sum = 0;
	int top = 0, bottom = 4, left = 0, right = 4;
	int i = 0, j = 0;

	while (top <= bottom && left <= right) {
		//��� ��
		for (j = left; j <= right; j++) {
			aList[top][j] = ++sum;
		}
		top++;

		//���� ��
		for (i = top; i <= bottom; i++) {
			aList[i][right] = ++sum;
		}
		right--;

		//�ϴ� ��
		if (top <= bottom) {
			for (j = right; j >= left; j--) {
				aList[bottom][j] = ++sum;
			}
			bottom--;
		}

		//���� ��
		if (left <= right) {
			for (i = bottom; i >= top; i--) {
				aList[i][left] = ++sum;
			}
			left++;
		}
	}

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			printf("%2d ", aList[i][j]);
		}
		printf("\n");
	}

	return 0;
}

void lookup_array() {
	//��ü ��쿡 ���� ���ݷ� ����� ���� �迭�� ���� �� ����
	double aRate[10] = {
		0.0, 0.1, 0.25, //1~3�� 0%, 10%, 25%
		0.5, 0.5,	//4~5��
		0.6, 0.65,	//6~7��
		0.8, 0.82, 0.97	//8~10��
	};
	int nAge = 0, nFee = 1000;

	printf("���ǥ");
	for (int i = 1; i <= 10; i++) {
		printf("%2d�� ���: %3d��\n", i, (int)(nFee * aRate[i - 1]));
	}

	printf("���̸� �Է��ϼ���. : ");
	if (scanf_s("%d", &nAge) != 1) {
		printf("�߸��� �Է��Դϴ�. ���̸� ���ڷ� �Է����ּ���.\n");
		return 1; // �Է� ���� �� ����
	}

	if (nAge < 1) {
		nAge = 1;
	}
	else if (nAge > 10) {
		nAge = 10;
	}
	printf("���� ���: %d\n", (int)(nFee * aRate[nAge - 1]));

	return 0;
}

static void ex1_input(int *a, int *b, int *c) {
	printf("�� ������ �Է��ϼ���: ");
	scanf_s("%d%d%d", a, b, c);
}

static int ex1_output(int a, int b, int c) {
	int inputMax = a;
	inputMax = (inputMax > b) ? inputMax : b;
	inputMax = (inputMax > c) ? inputMax : c;
	return inputMax;
}

void function_ex1() {
	int a = 0, b = 0, c = 0;
	int max = 0;
	//UI
	ex1_input(&a, &b, &c);
	//�ִ� ���
	max = ex1_output(a, b, c);
	
	printf("MAX : %d", max);
	return 0;
}

void pointer_ex1() {
	int nData = 10;
	printf("%s\n", "nData");
	
	printf("%d\n", nData);
	printf("%p\n", &nData);
	return 0;
}

void pointer_ex2() {
	int aList[5] = { 0 };
	int* pnData = aList;

	printf("aList[0] : %d\n", aList[0]);

	*pnData = 20;
	printf("aList[0]: %d\n", aList[0]);
	printf("pnData[0]: %d\n", pnData[0]);
}

void pointer_ex3() {
	//���ڿ��� ���� Ȯ��
	char szBuffer[16] = { "Hello" };
	char* pszData = szBuffer;

	while (*pszData != '\0')
		pszData++;

	printf("&pszData : %p, &szBuffer : %p\n", pszData, szBuffer);
	printf("Length : %d\n", pszData - szBuffer);

	return 0;
}