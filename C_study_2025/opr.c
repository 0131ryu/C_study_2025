#include <stdio.h>
#include "opr.h"

void operation_and_print(void) {
	int a = 10, b = 3;
	printf("plus : %d\n", a + b);
	printf("division : %d\n", a / b);
	printf("exc : %d\n", a % b); 
	return 0;
}