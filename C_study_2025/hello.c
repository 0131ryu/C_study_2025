#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "hello.h"

int hello_world() { //함수, int는 함수의 타입
	printf("hello, World!\n"); //문자(배)열, 구문을 의미
	return 0; //반환 값

	//문자열 = 문자(배열) char[15] 
	//문자열의 첫글자로 배열의 주소를 파악함 = 배열의 이름
}

void string_input_output() {
	char ch = 0; //변수 선언 + 정의
	ch = getchar(); //한 글자만 저장
	putchar(ch);
	putchar('Z');
	
	return 0;
}

void string_input_output_non_buffered() {
	char ch = 0;
	printf("아무 키나 누르면 다음으로 넘어갑니다.\n");

	ch = _getch();
	
	printf("입력한 키는 ");
	putchar(ch);
	printf("입니다.");
	return 0;
}

void example_string_array() {
	char szName[32] = { 0 };
    printf("이름을 입력하세요: ");

    if (fgets(szName, sizeof(szName), stdin)) { //szName 주소 정보
        // 개행 문자 제거
        szName[strcspn(szName, "\n")] = 0;
    }

    printf("당신의 이름은 ");
    puts(szName);
    printf("입니다.\n");

    return 0;
}

void form_char(void) {
	int x = 10;

	putchar('B');
	putchar('\n');
	printf("%c\n", 65); //A

	printf("x는 %d입니다\n\a", x);
	
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

	printf("나이를 입력하세요. : ");
	scanf_s("%d%*c", &nAge); // %*c = \n을 지워줌

	printf("이름을 입력하세요. : ");
	gets_s(szName, sizeof(szName));

	printf("%d세 %s\n", nAge, szName);

	return 0;
}

void szBuffer_left_right() {
	char szBuffer[32] = { 0 };

	//사용자가 입력한 문자열을 배열에 저장하고 출력
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

	printf("나이를 입력하세요: ");
	scanf_s("%d%*c", &szAge);

	printf("이름을 입력하세요: ");
	gets_s(szName, sizeof(szName));

	printf("당신의 나이는 %d살이고 이름은 '%s'입니다.", szAge, szName);
	return 0;
}

void two_int_result_double() {
	int a = 0, b = 0;
	double result = 0;

	printf("두 정수를 입력하세요. : ");
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

	printf("%d초는 %02d시간 %02d분 %02d초입니다.",
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

	result = a + (~b + 1); // a- b와 동일, 보수 이용

	printf("%d", result);
	return 0;
}

void acceptance_or_failure() {
	int score = 0;

	printf("점수를 입력하세요 : ");
	scanf_s("%d", &score);

	printf("%s", score >= 80 ? "합격" : "불합격");

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

	printf("나이 : %d, 최종요금: %d원", age, bus_fare);
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
	printf("요금은 %d원", (int)fee);
	return 0;
}

void show_star_number() {
	int input = 0, i = 0;

	scanf_s("%d", &input);

	while (input < 1 || input > 9) {
		puts("1~9 사이의 값을 입력 바랍니다.");
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