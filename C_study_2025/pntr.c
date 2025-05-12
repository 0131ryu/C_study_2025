#include <stdio.h>
#include "pntr.h"

void dereferencing_indirection_ex1() {
	int *a, b;
	b = 100; //b�� 100�� ġȯ
	a = &b; //a�� b�� �ּҸ� ġȯ
	printf("%d", *a); // �����͸� �̿��ؼ� ���� ���
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
	int* q = a + 2; //a[2]�� ���� ����Ŵ

	printf("%d\n", *a); //1
	printf("%d\n", *(a+1)); //2
	printf("%d\n", *(p+2)); //3
	printf("%d\n", *(q+3)); 
	//a[5]�� �ּҸ� ����Ű�� �ʱ�ȭ �������� �Ҵ���� ����, 0���� �ʱ�ȭ
	return 0;
}

void exam_pointer_ex2() {
	int i = 10, *ip = &i; //ip�� i�� ����Ŵ
	int j, k;
	char c = 'D', * cp = &c; //cp�� c�� ����Ŵ
	double* jp = (double*)2000; 
	//��������� �ּ� 2000���� ĳ����, ������ ������ Ư�� �޸� �ּ� ����Ű���� ����
	*ip++ = ++i; //1 ����, 11 -> 1���� 12
	++*--ip; //��������� 12�� ������, i = 13, --ip�� ���� 1�� ���� �� 12
	++*cp++; //D(ASCII �ڵ� 68) + 1 = 69, ���ڴ� E�� �ǹ�
	*--cp = c + 3; //E���� + 3, 69 + 3 = 72, 72�� �ش��ϴ� ���� H
	jp += 5; //dobule �� = 8qkdlxm => 5 * 8 = 40 => 2000 + 40 = 2040
	j = jp - (double*)80; //(2040 -80) = 1960 / 8 = 245
	k = (int)(jp - 80); //(2040 - (80 * 8) = 2040 - 640 = 1400
	printf("i = %d, j = %d, k = %d, c = %c\n", i, j, k, c);
	//i = 12, j = 245, k = 1400, c = H
	return 0;
}