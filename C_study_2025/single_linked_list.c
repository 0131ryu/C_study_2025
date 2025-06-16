#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "single_linked_list.h"

typedef struct USERDATA
{
	int age;
	char name[32];
	char phone[32];
	struct USERDATA* pNext;
} USERDATA;

USERDATA* g_single_pHeadNode = NULL;

void single_AddNewNode(int age, const char *pszName, const char *pszPhone)
{
	USERDATA* pNewNode = (USERDATA*)malloc(sizeof(USERDATA));
	pNewNode->age = age;
	strcpy_s(pNewNode->name, sizeof(pNewNode->name), pszName);
	strcpy_s(pNewNode->phone, sizeof(pNewNode->phone), pszPhone);
	pNewNode->pNext = NULL;

	if (g_single_pHeadNode == NULL)
		g_single_pHeadNode = pNewNode;
	else
	{
		//Queue
		USERDATA* pTail = g_single_pHeadNode;
		while (pTail->pNext != NULL) {
			pTail = pTail->pNext;
		}

		pTail->pNext = pNewNode;
		//STACK
		//pNewNode->pNext = g_single_pHeadNode;
		//g_single_pHeadNode = pNewNode;
	}
}

void single_ReleasedList(void)
{
	USERDATA* pTmp = g_single_pHeadNode;
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
	g_single_pHeadNode = NULL;
}

void single_InitDummyData(void) {
	//Input
	single_AddNewNode(10, "Hoon", "010-1111-1111");
	single_AddNewNode(11, "Choi", "010-2222-2222");
	single_AddNewNode(12, "Jang", "010-3333-3333");
}

void single_PrintList(void) {
	USERDATA* pTmp = g_single_pHeadNode;
	while (pTmp != NULL)
	{
		printf("[%p] %d %s %s [%p]\n",
			pTmp, pTmp->age, pTmp->name, pTmp->phone, pTmp->pNext);
		pTmp = pTmp->pNext;
	}
	putchar('\n');
}

USERDATA* single_searchByName(const char* pszName) {
	USERDATA* pTmp = g_single_pHeadNode;
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

USERDATA* single_searchToRemove(USERDATA **ppPrev, const char* pszName) 
{	
	USERDATA* pCurrent = g_single_pHeadNode;
	USERDATA* pPrev = NULL;

	while (pCurrent != NULL)
	{
		if (strcmp(pCurrent->name, pszName) == 0)
		{
			*ppPrev = pPrev;
			return pCurrent;
		}
		pPrev = pCurrent; //앞전 노드 넘어가기전 저장
		pCurrent = pCurrent->pNext;
	}
	printf("\"%s\": Not found\n", pszName);
	return NULL;
}

void single_RemoveNode(USERDATA* pPrev) 
{
	USERDATA* pRemove = NULL;

	if (pPrev == NULL) //헤드 노드
	{
		if (g_single_pHeadNode == NULL) {
			return;
		}
		else {
			pRemove = g_single_pHeadNode;
			g_single_pHeadNode = pRemove->pNext; //다음 노드로 이동
			printf("Remove : %s\n", pRemove->name);
			free(pRemove);
		}
		return;
	}
	pRemove = pPrev->pNext;
	pPrev->pNext = pRemove->pNext;
	printf("Remove : %s\n", pRemove->name);
	free(pRemove); 
}

void single_TestStep01() {
	puts("single_TestStep01()---------------------------------");
	single_AddNewNode(11, "Choi", "010-2222-2222");
	single_AddNewNode(10, "Hoon", "010-1111-1111");
	single_AddNewNode(12, "Jang", "010-3333-3333");
	single_PrintList();

	//Search and Remove
	USERDATA* pPrev = NULL;
	if (single_searchToRemove(&pPrev, "Choi") != NULL) {
		single_RemoveNode(pPrev);
	}
	single_ReleasedList();
	putchar('\n');
}

void single_TestStep02() {
	puts("single_TestStep02()---------------------------------");
	single_AddNewNode(11, "Choi", "010-2222-2222");
	single_AddNewNode(10, "Hoon", "010-1111-1111");
	single_AddNewNode(12, "Jang", "010-3333-3333");
	single_PrintList();

	//Search and Remove
	USERDATA* pPrev = NULL;
	if (single_searchToRemove(&pPrev, "Hoon") != NULL) {
		single_RemoveNode(pPrev);
	}
	single_ReleasedList();
	putchar('\n');
}

void single_TestStep03() {
	puts("single_TestStep03()---------------------------------");
	single_AddNewNode(11, "Choi", "010-2222-2222");
	single_AddNewNode(10, "Hoon", "010-1111-1111");
	single_AddNewNode(12, "Jang", "010-3333-3333");
	single_PrintList();

	//Search and Remove
	USERDATA* pPrev = NULL;
	if (single_searchToRemove(&pPrev, "Jang") != NULL) {
		single_RemoveNode(pPrev);
	}
	single_ReleasedList();
	putchar('\n');
}


void single_example_1() {
	single_TestStep01();
	single_TestStep02();
	single_TestStep03();

	single_ReleasedList();
}
