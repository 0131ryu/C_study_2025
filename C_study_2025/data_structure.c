#include <stdio.h>
#include <stdlib.h>
#include "data_structure.h"

typedef struct USERDATA
{
	int age;
	char name[32];
	char phone[32];
	struct USERDATA* pNext;
} USERDATA;

void data_structure_ex1() {
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
}

void data_structure_ex2() {
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

	while(pUser != NULL) 
	{
		printf("[%p] %d, %s, %s, [%p]\n",
			pUser, pUser->age, pUser->name, pUser->phone,
			pUser->pNext);
		pUser = pUser->pNext;
	}
}

void LoadList()
{
	FILE* fp = NULL;
	fopen_s(&fp, "listData.dat", "rb");
	if (fp == NULL)
	{
		puts("ERROR: Failed to open listData.dat");
		return 0;
	}

	USERDATA user = { 0 };
	while (fread(&user, sizeof(USERDATA), 1, fp) > 0)
	{
		printf("%d, %s, %s\n",
			user.age, user.name, user.phone);
		memset(&user, 0, sizeof(USERDATA));
	}
	fclose(fp);
}

void file_data_structure_ex3() {
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

	FILE* fp = NULL;
	fopen_s(&fp, "listData.dat", "rb");
	if (fp == NULL)
	{
		puts("ERROR: Failed to open listData.dat");
		return 0;
	}

	USERDATA* pUser = &aList[0];
	while (pUser != NULL)
	{
		fwrite(pUser, sizeof(USERDATA), 1, fp);
		pUser = pUser->pNext;
	}
	fclose(fp);

	LoadList();
	return 0;
}

//전역 변수
USERDATA* g_pHeadNode = NULL;

void AddNewNode(int age, const char *pszName, const char *pszPhone) 
{
	USERDATA* pNewNode = (USERDATA*)malloc(sizeof(USERDATA));
	pNewNode->age = age;
	strcpy_s(pNewNode->name, sizeof(pNewNode->name), pszName);
	strcpy_s(pNewNode->phone, sizeof(pNewNode->phone), pszPhone);
	pNewNode->pNext = NULL;

	if (g_pHeadNode == NULL)
	{
		g_pHeadNode = pNewNode;
	}
	else {
		//순서대로 출력(Queue)
		USERDATA* pTail = g_pHeadNode;
		while (pTail->pNext != NULL) {
			pTail = pTail->pNext;
		}
		pTail->pNext = pNewNode;

		//역순으로 출력(Stack)
		//pNewNode->pNext = g_pHeadNode;
		//g_pHeadNode = pNewNode;
	}
}

void InitDummyData(void)
{
	//Input
	AddNewNode(10, "Hoon", "010-1111-1234");
	AddNewNode(11, "Choi", "010-2222-1234");
	AddNewNode(13, "Jang", "010-3333-1234");

}

void ReleaseList() {
	USERDATA* pTmp = g_pHeadNode;
	USERDATA* pDelete;
	while (pTmp != NULL) {
		pDelete = pTmp; //백업
		pTmp = pTmp->pNext;

		printf("DELETE: [%p] %d %s %s [%p]\n",
			pDelete, pDelete->age, pDelete->name, pDelete->phone, pDelete->pNext);

		free(pDelete);

	}
	g_pHeadNode = NULL; //추가해야 함
}

void PrintList(void)
{
	//Print list
	USERDATA* pTmp = g_pHeadNode;
	while (pTmp != NULL)
	{
		printf("START: [%p] %d %s %s [%p]\n",
			pTmp, pTmp->age, pTmp->name, pTmp->phone, pTmp->pNext);
		pTmp = pTmp->pNext;
	}
}

void node_ex4() {
	InitDummyData(); //더미데이터
	
	PrintList(); //값 출력
	
	ReleaseList(); //값 해제
	return 0;
}