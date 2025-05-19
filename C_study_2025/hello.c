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