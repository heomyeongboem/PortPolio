#include <stdio.h>
#include "SLinkedList.h"
#include<malloc.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
//주신 c파일과 pdf 파일의 출력 내용이 달라 c파일을 기준으로 하였습니다.
int main() {
	linkedList* L;
	listNode* p;

	L = (linkedList*)malloc(sizeof(linkedList));
	L->head = NULL;
	L->length = 0;

	printf("(1)공백리스트 생성하기\n");

	// Fill your code
	displayList(L);
	printf("리스트에 저장된 데이터 개수:%d\n", getLength(L));


	printf("\n(2)리스트에 월, 화, 목 노드를 순서대로 삽입하기\n");

	// Fill your code

	char* s1 = {"월"};
	char* y = { "화" };
	char* z = { "목" };
	
	insertLast(L, s1);
	insertLast(L, y);
	insertLast(L, z);
	displayList(L);
	printf("리스트에 저장된 데이터 개수:%d\n", getLength(L));
	
	printf("\n(3)목 노드 뒤에 일 노드 삽입하기\n");

	// Fill your code
	char* s2 = {"일"};
	linkedList* k = search(L,z);
	insert(L, k, s2);
	displayList(L);
	printf("리스트에 저장된 데이터 개수:%d\n", getLength(L));

	printf("\n(4)리스트에서 수 노드 탐색하기\n");
	char s3 = { "수" };
	// Fill your code
	if(NULL==search(L,s3))printf("찾는 데이터가 없습니다.\n");



	printf("\n(5)리스트 순서를 역순으로 바꾸기\n");

	// Fill your code
	reverse(L);
	displayList(L);
	printf("리스트에 저장된 데이터 개수:%d\n", getLength(L));

	clear(L);

	return 0;
}
