#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "double_linked_list.h"

typedef enum MY_MENU { EXIT, NEW, SEARCH, PRINT, REMOVE } MY_MENU;

typedef struct USERDATA
{
	int age;
	char name[32];
	char phone[32];
	struct USERDATA* pPrev;
	struct USERDATA* pNext;
} USERDATA;

//USERDATA* g_double_pHeadNode = NULL;
USERDATA g_double_HeadNode = { 0, "__double Head__" };
USERDATA g_double_TailNode = { 0, "__double Tail__" };

MY_MENU double_PrintMenu(void) {
	MY_MENU input = 0;

	system("cls");
	printf("[1]New\t[2]Search\t[3]Print\t[4]Remove\t[0]Exit\n");
	scanf_s("%d%*c", &input);
	return input;
}

void double_EventLoopRun(void)
{
	MY_MENU menu = 0;

	while ((menu = double_PrintMenu() != 0))
	{
		switch (menu)
		{
		case NEW:
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

void double_AddNewNode(int age, const char* pszName, const char* pszPhone)
{
	USERDATA* pNewNode = (USERDATA*)malloc(sizeof(USERDATA));
	pNewNode->age = age;
	strcpy_s(pNewNode->name, sizeof(pNewNode->name), pszName);
	strcpy_s(pNewNode->phone, sizeof(pNewNode->phone), pszPhone);
	pNewNode->pPrev = NULL;
	pNewNode->pNext = NULL;

	USERDATA* pPrevNode = g_double_TailNode.pPrev;
	pNewNode->pPrev = g_double_TailNode.pPrev;;
	pNewNode->pNext = &g_double_TailNode;

	pPrevNode->pNext = pNewNode;
	g_double_TailNode.pPrev = pNewNode;
}

void double_InitList(void)
{
	g_double_HeadNode.pNext = &g_double_TailNode;
	g_double_TailNode.pPrev = &g_double_HeadNode;
}

void double_ReleasedList(void)
{
	USERDATA* pTmp = g_double_HeadNode.pNext;
	USERDATA* pDelete;
	while (pTmp != NULL && pTmp != &g_double_TailNode) //추가
	{
		pDelete = pTmp;
		pTmp = pTmp->pNext;

		printf("Delete : [%p] %d %s %s [%p]\n",
			pDelete,
			pDelete->age, pDelete->name, pDelete->phone, pDelete->pNext);

		free(pDelete); //해제하는 대상
	}
	double_InitList();
}

void double_InitdoubleData(void) {
	//Input
	double_AddNewNode(10, "Hoon", "010-1111-1111");
	double_AddNewNode(11, "Choi", "010-2222-2222");
	double_AddNewNode(12, "Jang", "010-3333-3333");
}

void double_PrintList(void) {
	USERDATA* pTmp = &g_double_HeadNode;
	while (pTmp != NULL)
	{
		printf("[%p] %d %s %s [%p]\n",
			pTmp, pTmp->age, pTmp->name, pTmp->phone, pTmp->pNext);
		pTmp = pTmp->pNext;
	}
	putchar('\n');
}

void double_PrintListReverse(void) {
	USERDATA* pTmp = &g_double_TailNode;
	while (pTmp != NULL)
	{
		printf("[%p] %d %s %s [%p]\n",
			pTmp, pTmp->age, pTmp->name, pTmp->phone, pTmp->pNext);
		pTmp = pTmp->pPrev;
	}
	putchar('\n');
}

USERDATA* double_searchByName(const char* pszName) {
	USERDATA* pTmp = g_double_HeadNode.pNext;
	while (pTmp != NULL)
	{
		if (strcmp(pTmp->name, pszName) == 0)
		{
			printf("\"%s\": Found\n", pszName);
			return pTmp;
		}
		pTmp = pTmp->pNext;
	}
	printf("\"%s\": Not found\n", pszName);
	return NULL;
}

void double_RemoveNode(USERDATA* pRemove)
{
	USERDATA* pPrev = pRemove->pPrev;
	USERDATA* pNext = pRemove->pNext;

	pPrev->pNext = pRemove->pNext;
	pNext->pPrev = pRemove->pPrev;

	printf("Remove : %s\n", pRemove->name);
	free(pRemove);
}

void double_TestStep01() {
	puts("double_TestStep01()---------------------------------");
	double_AddNewNode(11, "Choi", "010-2222-2222");
	double_AddNewNode(10, "Hoon", "010-1111-1111");
	double_AddNewNode(12, "Jang", "010-3333-3333");
	double_PrintList();

	//Search and Remove
	USERDATA* pPrev = double_searchByName("Choi");
	if (pPrev != NULL) {
		double_RemoveNode(pPrev);
	}
	double_PrintListReverse();
	double_ReleasedList();
	putchar('\n');
}

void double_TestStep02() {
	puts("double_TestStep02()---------------------------------");
	double_AddNewNode(11, "Choi", "010-2222-2222");
	double_AddNewNode(10, "Hoon", "010-1111-1111");
	double_AddNewNode(12, "Jang", "010-3333-3333");
	double_PrintList();

	//Search and Remove
	USERDATA* pPrev = double_searchByName("Hoon");
	if (pPrev != NULL) {
		double_RemoveNode(pPrev);
	}
	double_ReleasedList();
	putchar('\n');
}

void double_TestStep03() {
	puts("double_TestStep03()---------------------------------");
	double_AddNewNode(11, "Choi", "010-2222-2222");
	double_AddNewNode(10, "Hoon", "010-1111-1111");
	double_AddNewNode(12, "Jang", "010-3333-3333");
	double_PrintList();

	//Search and Remove
	USERDATA* pPrev = double_searchByName("Jang");
	if (pPrev != NULL) {
		double_RemoveNode(pPrev);
	}
	double_ReleasedList();
	putchar('\n');
}

int double_IsEmpty(void)
{
	if (g_double_HeadNode.pNext == &g_double_TailNode) //데이터 없음
		return 1;
	return 0;
}

void double_Push(USERDATA* pUser)
{
	USERDATA* pNewNode = (USERDATA*)malloc(sizeof(USERDATA));
	memcpy(pNewNode, pUser, sizeof(USERDATA));
	pNewNode->pPrev = NULL;
	pNewNode->pNext = NULL;

	//USERDATA* pNextNode = g_double_HeadNode.pNext;
	pNewNode->pPrev = &g_double_HeadNode;
	pNewNode->pNext = g_double_HeadNode.pNext;

	g_double_HeadNode.pNext->pPrev = pNewNode;
	g_double_HeadNode.pNext = pNewNode;

}

USERDATA* double_Pop(void)
{
	if (double_IsEmpty())
	{
		puts("Error : Stack Underflow.");
		return NULL;
	}
	USERDATA* pPop = g_double_HeadNode.pNext;
	g_double_HeadNode.pNext = pPop->pNext;
	if (pPop->pNext != NULL) // Check if pPop->pNext is not NULL
	{
		pPop->pNext->pPrev = &g_double_HeadNode;
	}
	return pPop;
}

USERDATA* double_Dequeue(void)
{
	return double_Pop();
}

void double_Enqueue(USERDATA* pUser) {
	double_AddNewNode(pUser->age, pUser->name, pUser->phone);
}

void dobule_TestStackAndQueue(void)
{
		USERDATA user = { 10, "Test01"};
	//double_Push(&user);
	double_Enqueue(&user);

	user.age = 11;
	strcpy_s(user.name, sizeof(user.name), "Test02");
	//double_Push(&user);
	double_Enqueue(&user);

	user.age = 12;
	strcpy_s(user.name, sizeof(user.name), "Test03");
	//double_Push(&user);
	double_Enqueue(&user);

	for (int i = 0; i < 3; i++) {
		//USERDATA* pUser = double_Pop();
		USERDATA* pUser = double_Dequeue();
		printf("Pop: %d, %s\n", pUser->age, pUser->name);
		free(pUser);
	}
}

void double_example_1() {
	double_InitList();

	dobule_TestStackAndQueue();

	double_PrintList();
	double_ReleasedList();
}