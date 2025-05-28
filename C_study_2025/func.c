#include <stdio.h>
#include "func.h"


//포인터로 문자열 배열을 받고 반환 타입도 char*로 수정
char* MyStrcpy(char* szBufferDst, size_t dstSize, char* szBufferSrc) {

	strcpy_s(szBufferDst, dstSize - 1, szBufferSrc);
	szBufferDst[dstSize - 1] = '\0';

	return szBufferDst;
}

char* MyStrcpy2(char* szBufferDst, unsigned int dstSize, char* szBufferSrc) {

	size_t nLenSrc = 0;
	nLenSrc = strlen(szBufferSrc);

	for (int i = 0; i < nLenSrc; i++) {
		szBufferDst[i] = szBufferSrc[i];
	}
}

void function_ex_strcpy() {
	char szBufferSrc[12] = { "TestString" };
	char szBufferDst[12] = { 0 };

	char szBufferSrc2[12] = { "StringTest" };
	char szBufferDst2[12] = { 0 };

	MyStrcpy(szBufferDst, sizeof(szBufferDst), szBufferSrc);
	puts(szBufferDst);

	puts("----------------------------------------------");
	MyStrcpy2(szBufferDst2, sizeof(szBufferDst2), szBufferSrc2);
	puts(szBufferDst2);
	return 0;
}

int GetFactorial(int nParam)
{
	int nResult = 0;
	if (nParam == 1) return 1;

	nResult = nParam * GetFactorial(nParam - 1);
	return nResult;
}

void recursive_function() {
	printf("5 !== %d\n", GetFactorial(5));
}

void PutData(char* pszParam) {
	if (*pszParam == '\0')
		return;

	putchar(*pszParam);
	PutData(pszParam + 1);
}

void recursive_function2() {
	PutData("TestData");
	putchar('\n');
}

void string_processing() {
	char szBuffer[128] = { "nData = x + y;\nnResult = a * b" };
	char* pszSep = " *+=;\n";
	char* pszToken = NULL;
	char* pszNextToken = NULL;

	pszToken = strtok_s(szBuffer, pszSep, &pszNextToken);
	while (pszToken != NULL) 
	{
		puts(pszToken);
		pszToken = strtok_s(NULL, pszSep, &pszNextToken);
	}
	printf("\nszBuffer: %s\n", szBuffer);
}

void join_string() {
	char szPath[128] = { 0 };
	char szBuffer[128] = { 0 };

	printf("Input path : ");
	gets_s(szBuffer, sizeof(szBuffer));

	sprintf_s(szPath, sizeof(szPath) / sizeof(char),
		"C:\\Program Files\\%s", szBuffer);
	puts(szPath);
}

char* mystrcat(char* pszDst, char* pszSrc) {
	while (*pszDst != '\0')
		++pszDst;
	while (*pszSrc != '\0')
		*pszDst++ = *pszSrc++;

	*++pszDst = '\0';
	return --pszDst;
}

void join_string2() {
	char szPath[128] = { 0 };
	char* pszEnd = NULL;

	pszEnd = mystrcat(szPath, "C:\\Program Files\\");
	pszEnd = mystrcat(pszEnd, "CHS\\");
	pszEnd = mystrcat(pszEnd, "C programing");

	puts(szPath);
	return 0;
}