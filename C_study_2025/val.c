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
