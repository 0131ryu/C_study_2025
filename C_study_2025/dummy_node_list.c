#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "dummy_node_list.h"

typedef struct USERDATA
{
	int age;
	char name[32];
	char phone[32];
	struct USERDATA* pNext;
} USERDATA;

//USERDATA* g_dummy_pHeadNode = NULL;
USERDATA g_dummy_HeadNode = { 0, "__Dummy Node__" };

void dummy_AddNewNode(int age, const char* pszName, const char* pszPhone)
{
	USERDATA* pNewNode = (USERDATA*)malloc(sizeof(USERDATA));
	pNewNode->age = age;
	strcpy_s(pNewNode->name, sizeof(pNewNode->name), pszName);
	strcpy_s(pNewNode->phone, sizeof(pNewNode->phone), pszPhone);
	pNewNode->pNext = NULL;


	//Queue
	USERDATA* pTail = &g_dummy_HeadNode;
	while (pTail->pNext != NULL) {
		pTail = pTail->pNext;
	}
	pTail->pNext = pNewNode;
}

void dummy_ReleasedList(void)
{
	USERDATA* pTmp = g_dummy_HeadNode.pNext;
	USERDATA* pDelete;
	while (pTmp != NULL)
	{
		pDelete = pTmp;
		pTmp = pTmp->pNext;

		printf("Delete : [%p] %d %s %s [%p]\n",
			pDelete,
			pDelete->age, pDelete->name, pDelete->phone, pDelete->pNext);

		free(pDelete); //해제하는 대상
	}
	g_dummy_HeadNode.pNext = NULL;
}

void dummy_InitDummyData(void) {
	//Input
	dummy_AddNewNode(10, "Hoon", "010-1111-1111");
	dummy_AddNewNode(11, "Choi", "010-2222-2222");
	dummy_AddNewNode(12, "Jang", "010-3333-3333");
}

void dummy_PrintList(void) {
	USERDATA* pTmp = &g_dummy_HeadNode;
	while (pTmp != NULL)
	{
		printf("[%p] %d %s %s [%p]\n",
			pTmp, pTmp->age, pTmp->name, pTmp->phone, pTmp->pNext);
		pTmp = pTmp->pNext;
	}
	putchar('\n');
}

USERDATA* dummy_searchByName(const char* pszName) {
	USERDATA* pTmp = g_dummy_HeadNode.pNext;
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

USERDATA* dummy_searchToRemove(const char* pszName)
{
	USERDATA* pPrev = &g_dummy_HeadNode;

	while (pPrev->pNext != NULL)
	{
		if (strcmp(pPrev->pNext->name, pszName) == 0)
			return pPrev;
		pPrev = pPrev->pNext;
	}
	printf("\"%s\": Not found\n", pszName);
	return NULL;
}

void dummy_RemoveNode(USERDATA* pPrev)
{
	USERDATA* pRemove = NULL;

	if (pPrev == NULL) //헤드 노드
	{
		pRemove = pPrev->pNext;
		pPrev->pNext = pRemove->pNext; //다음 노드로 이동
		printf("Remove : %s\n", pRemove->name);
		free(pRemove);

		return;
	}
	pRemove = pPrev->pNext;
	pPrev->pNext = pRemove->pNext;
	printf("Remove : %s\n", pRemove->name);
	free(pRemove);
}

void dummy_TestStep01() {
	puts("dummy_TestStep01()---------------------------------");
	dummy_AddNewNode(11, "Choi", "010-2222-2222");
	dummy_AddNewNode(10, "Hoon", "010-1111-1111");
	dummy_AddNewNode(12, "Jang", "010-3333-3333");
	dummy_PrintList();

	//Search and Remove
	USERDATA* pPrev = dummy_searchToRemove("Choi");
	if (pPrev != NULL) {
		dummy_RemoveNode(pPrev);
	}
	dummy_ReleasedList();
	putchar('\n');
}

void dummy_TestStep02() {
	puts("dummy_TestStep02()---------------------------------");
	dummy_AddNewNode(11, "Choi", "010-2222-2222");
	dummy_AddNewNode(10, "Hoon", "010-1111-1111");
	dummy_AddNewNode(12, "Jang", "010-3333-3333");
	dummy_PrintList();

	//Search and Remove
	USERDATA* pPrev = dummy_searchToRemove("Hoon");
	if (pPrev != NULL) {
		dummy_RemoveNode(pPrev);
	}
	dummy_ReleasedList();
	putchar('\n');
}

void dummy_TestStep03() {
	puts("dummy_TestStep03()---------------------------------");
	dummy_AddNewNode(11, "Choi", "010-2222-2222");
	dummy_AddNewNode(10, "Hoon", "010-1111-1111");
	dummy_AddNewNode(12, "Jang", "010-3333-3333");
	dummy_PrintList();

	//Search and Remove
	USERDATA* pPrev = dummy_searchToRemove("Jang");
	if (pPrev != NULL) {
		dummy_RemoveNode(pPrev);
	}
	dummy_ReleasedList();
	putchar('\n');
}


void dummy_example_1() {
	dummy_TestStep01();
	dummy_TestStep02();
	dummy_TestStep03();

	dummy_ReleasedList();
}