#include <stdio.h>
#include "str.h"

void return_str() {
	char str1[8] = "Example";
	char str2[3] = {'i', 's' };
	char str3[] = "better than precept.";

	printf("%s %s %s\n", str1, str2, str3);
	return 0;
}

void change_str() {
	char str[] = "str-ng";
	printf("before %s\n", str);
	str[3] = 'i';
	printf("after %s\n", str);
	return 0;
}

void pointer_str() {
	char* str = "string";

	printf("%s\n", str);
	printf("%p\n", str);
	return 0;
}

void pointer_change_str() {
	char* str = "str-ng"; //포인터에 문자열 "string" 주소 저장
	printf("before %s\n", str); 

	str[3] = 'i'; 
	printf("after %s\n", str); //출력 X, 문자열 포인터는 요소에 문자 할당 불가함`
	printf("after %c\n", str[3]); //출력 X
	return 0;
}

void use_fgets_str() {
	char str[100];

	printf("문자열 입력 : ");
	if (fgets(str, sizeof(str), stdin) != NULL) {
		printf("문자열 출력 : ");
		printf("%s", str);
	}
	else {
		printf("입력 오류 발생 또는 EOF\n");
	}

	return 0;
}

void use_fgets_str_ex2() {
	char dep_name[100];
	char stud_name[100];

	printf("학과명 입력 : ");
	if (fgets(dep_name, sizeof(dep_name), stdin) == NULL) {
		printf("오류 있음");
		return 1;
	}

	printf("학생명 입력 : ");
	if (fgets(stud_name, sizeof(stud_name), stdin) == NULL) {
		printf("오류 있음");
		return 1;
	}

	printf("%s", dep_name);
	printf("%s", stud_name);

	return 0;
}

void length_sizeof_str() {
	char str[50] = "string length";

	printf("%s\n", str);
	printf("문자열 길이 : %d\n", strlen(str));
	printf("배열 길이 : %d\n", sizeof(str));
	return 0;
}

void copy_str() {
	char str1[] = "banana";
	char str2[] = "orange";

	printf("%s, %s\n", str1, str2);

	strcpy(str1, str2);
	printf("%s, %s\n", str1, str2);
	return 0;
}

void compare_str() {
	char str1[50] = "orange";
	char str2[50] = "banana";
	char temp[50];
	int cmp_result;

	printf("before : %s, %s\n", str1, str2);

	cmp_result = strcmp(str1, str2);

	if (cmp_result > 0) {
		strcpy(temp, str1);
		strcpy(str1, str2);
		strcpy(str2, temp);
	}

	printf("after: %s, %s\n", str1, str2);

	return 0;
}

void connect_str() {
	char str1[10] = "ing";
	char str2[10] = "str";

	strcat(str2, str1);

	printf("%s\n", str2);
	return 0;
}

void compare_str_ex() {
	char str1[] = "string";
	char str2[] = "string";

	int str_cmp = strcmp(str1, str2);

	printf("%d\n", str_cmp);
}

void change_str_ex() {
	char fruit1[20] = "Cherry";
	char fruit2[] = "Durian";
	int cmp;

	cmp = strcmp(fruit1, fruit2);

	printf("비교 결과 : %d\n", cmp);
	return 0;
}