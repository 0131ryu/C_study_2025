#include <stdio.h>
#include <conio.h>
#include "basic_theory.h"

typedef struct USERDATA
{
	int age;
	char name[32];
	char phone[32];
	struct USERDATA* pNext;
} USERDATA;

void example_1() {
	USERDATA aList[4] = {
		{20, "Tester01", "010-1234-1111", NULL},
		{21, "Tester02", "010-1234-2222", NULL},
		{22, "Tester03", "010-1234-3333", NULL},
		{23, "Tester04", "010-1234-4444", NULL}
	};

	aList[0].pNext = &aList[1];
	aList[1].pNext = &aList[2];
	aList[2].pNext = &aList[3];
	aList[3].pNext = NULL;

	printf("%s\n", aList[0].name);
	printf("%s\n", aList[0].pNext->name);
	printf("%s\n", aList[0].pNext->pNext->name);
	printf("%s\n", aList[0].pNext->pNext->pNext->name);
	putchar('\n');

	for (int i = 0; i < 4; i++)
		printf("%s\n", aList[i].name);

	return 0;
}

void example_2() {
	USERDATA aList[4] = {
	{20, "Tester01", "010-1234-1111", NULL},
	{21, "Tester02", "010-1234-2222", NULL},
	{22, "Tester03", "010-1234-3333", NULL},
	{23, "Tester04", "010-1234-4444", NULL}
	};
	//배열의 각 요소가 다음 요소를 가리키도록 함
	aList[0].pNext = &aList[1];
	aList[1].pNext = &aList[2];
	aList[2].pNext = &aList[3];
	aList[3].pNext = NULL;

	//가시성 확보
	USERDATA* pUser = &aList[0];

	while (pUser != NULL) {
		printf("[%p] %d, %s, %s, [next: %p]\n",
			pUser,
			pUser->age, pUser->name, pUser->phone,
			pUser->pNext);
		pUser = pUser->pNext;
	}
}

typedef enum MY_MENU {EXIT, NEW, SEARCH, PRINT, REMOVE} MY_MENU;

MY_MENU PrintMenu(void) {
	MY_MENU input = 0;

	system("cls");
	printf("[1]New\t[2]Search\t[3]Print\t[4]Remove\t[0]Exit\n");
	scanf_s("%d%*c", &input);
	return input;
}

void AddNewData(void) {
	puts("AddNewData()");
	puts("Press any key to continue....");
	_getch();
}

void example_3() {
	MY_MENU menu = 0;

	while ((menu = PrintMenu() != 0))
	{
		switch (menu)
		{
		case NEW:
			AddNewData();
			break;
		case SEARCH:
			break;
		case PRINT:
			break;
		case REMOVE:
			break;
		default:
			break;
		}
		printf("BYE!");
		return 0;
	}
}