#include <stdio.h>
#include <stdlib.h>
#include "str_data.h"

typedef struct USERDATA
{
	int nAge;
	char szName[32];
	char szPhone[32];
} USERDATA;

void user_data_ex() {
	USERDATA* pUser = NULL;

	pUser = (USERDATA*)malloc(sizeof(USERDATA));
	pUser->nAge = 10;
	strcpy_s(pUser->szName, sizeof(pUser->szName), "Hoon");
	strcpy_s(pUser->szPhone, sizeof(pUser->szPhone), "1234");

	printf("%d살\t%s\t%s\n", pUser->nAge, pUser->szName, pUser->szPhone);
	free(pUser);
	return 0;
}

void GetUserData2(USERDATA* pUser) { //구조체를 멤버로 사용
	//10살    Hoon    1234
	pUser->nAge = 10;
	strcpy_s(pUser->szName, sizeof(pUser->szName), "Hoon");
	strcpy_s(pUser->szPhone, sizeof(pUser->szPhone), "1234");

	return 0;
}

void user_data_ex2() {
	USERDATA user = { 0 };

	GetUserData2(&user);

	printf("%d살\t%s\t%s\n", user.nAge, user.szName, user.szPhone);
	return 0;
}

void GetUserData3(USERDATA* param) { //구조체를 멤버로 사용
	//10살    Hoon    1234
	USERDATA user = {
		10, "Hoon", "010-1234-5678"
	};

	*param = user;
	return 0;
}

void user_data_ex3() {
	USERDATA user = { 5, "Ho-sung", "010-1111-1234"};

	USERDATA result;

	GetUserData3(&result);
	printf("%d살\t%s\t%s\n", 
		result.nAge, result.szName, result.szPhone);
	return 0;
}

typedef struct USERDATAEX
{
	char szName[32];
	char szPhone[32];

	struct USERDATAEX* pNext; // 다음 USERDATAEX 구조체를 가리키는 포인터
} USERDATAEX;

void user_data_ex4() {
	USERDATAEX user = { "김두식", "1234", NULL };
	USERDATAEX newUser = { "이미현", "2345", NULL };

	user.pNext = &newUser; 
	//user 구조체의 pNext 멤버의 newUser 구조체의 메모리를 저장
	//user의 pNext가 newUser 구조체를 가리키도록 설정
	printf("%s, %s\n", user.szName, user.szPhone);

	printf("%s, %s\n", user.pNext -> szName, user.pNext->szPhone);
	return 0;
}

typedef struct USERDATAEXTWO
{
	char szName[32];
	char szPhone[32];
	struct USERDATAEXTWO* pNext;
} USERDATAEXTWO;

void PrintUserData(USERDATAEXTWO* pUser) //재귀호출
{
	if (pUser == NULL)
		return;

	printf("[%p] %s, %s, pNext:%p\n", 
		pUser, pUser->szName, pUser->szPhone, pUser->pNext);
	PrintUserData(pUser->pNext);
}

void user_data_ex5() {
	USERDATAEXTWO userList[4] = {
		{"김두식", "1234", NULL},
		{"이미현", "2345", NULL},
		{"김봉석", "3456", NULL},
		{"장희수", "4567", NULL}
	};

	USERDATAEXTWO* pUser = NULL;

	userList[0].pNext = &userList[1];
	userList[1].pNext = &userList[2];
	userList[2].pNext = &userList[3];
	userList[3].pNext = NULL; //연결 리스트의 마지막은 무조건 null
	

	PrintUserData(&userList[0]);

	/*pUser = &userList[0];
	while (pUser != NULL)
	{
		printf("%s, %s\n", pUser->szName, pUser->szPhone);
		pUser = pUser->pNext;
	}*/

	return 0;
}