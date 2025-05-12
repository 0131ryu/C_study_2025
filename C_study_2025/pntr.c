#include <stdio.h>
#include "pntr.h"

void dereferencing_indirection_ex1() {
	int *a, b;
	b = 100; //b에 100을 치환
	a = &b; //a에 b의 주소를 치환
	printf("%d", *a); // 포인터를 이용해서 값을 출력
	return 0;
}

void dereferencing_indirection_ex2() {
	int i;
	char* iptr;
	i = 256;
	iptr = (char*)&i;
	printf("%d\n", *iptr);
	return 0;
}

void pointer_operation_ex1() {
	int i, * iptr;
	i = 5;
	iptr = &i;
	printf("iptr = %p\n", iptr);
	iptr++;
	printf("iptr = %p\n", iptr);
	iptr = iptr + 2;
	printf("iptr = %p\n", iptr);
	return 0;
}

void swap(int* ip, int* jp) {
	int t;
	t = *ip;
	*ip = *jp;
	*jp = t;
}

void function_pointer_ex1() {
	void swap(int*, int*);
	int i = 10, j = 20;
	printf("i = %d, j = %d\n", i, j);
	swap(&i, &j);
	printf("i = %d, j = %d\n", i, j);
	return 0;
}

void change_int(int* ap, int* bp) {
	int trans;
	trans = *ap;
	*ap = *bp;
	*bp = trans;
}

void function_pointer_ex2() {
	void change_int(int*, int*);
	int a = 300, b = 500;
	printf("a = %d, b = %d\n", a, b);
	change_int(&a, &b);
	printf("a = %d, b = %d\n", a, b);
	return 0;
}

void exam_pointer_ex1() {
	int a[8] = { 1, 2, 3, 4, 5 };
	int* p = a;
	int* q = a + 2; //a[2]의 값을 가리킴

	printf("%d\n", *a); //1
	printf("%d\n", *(a+1)); //2
	printf("%d\n", *(p+2)); //3
	printf("%d\n", *(q+3)); 
	//a[5]의 주소를 가리키나 초기화 과정에서 할당되지 않음, 0으로 초기화
	return 0;
}

void exam_pointer_ex2() {
	int i = 10, *ip = &i; //ip는 i를 가리킴
	int j, k;
	char c = 'D', * cp = &c; //cp는 c를 가리킴
	double* jp = (double*)2000; 
	//명시적으로 주소 2000으로 캐스팅, 포인터 변수가 특정 메모리 주소 가리키도록 설정
	*ip++ = ++i; //1 증가, 11 -> 1증가 12
	++*--ip; //간접참고된 12를 증가함, i = 13, --ip로 인해 1이 빠짐 즉 12
	++*cp++; //D(ASCII 코드 68) + 1 = 69, 문자는 E를 의미
	*--cp = c + 3; //E에서 + 3, 69 + 3 = 72, 72에 해당하는 문자 H
	jp += 5; //dobule 형 = 8qkdlxm => 5 * 8 = 40 => 2000 + 40 = 2040
	j = jp - (double*)80; //(2040 -80) = 1960 / 8 = 245
	k = (int)(jp - 80); //(2040 - (80 * 8) = 2040 - 640 = 1400
	printf("i = %d, j = %d, k = %d, c = %c\n", i, j, k, c);
	//i = 12, j = 245, k = 1400, c = H
	return 0;
}