#include <stdio.h>
#include "opr.h"

int main() {
	logical_operation_and_print();
	printf("-----------------------------\n");
	bit_operation_and_print();
	printf("-----------------------------\n");
	compound_operation_and_print();
	printf("-----------------------------\n");
	priority_operation_and_print();
	return 0;
}