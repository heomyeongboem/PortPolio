#include <stdio.h>
#include "SLinkedList3.h"

int whoIsPrecede(element d1, element d2) {
	return d1 > d2 ? 0 : 1;
}

int main() {
	linkedList* L;
	listNode* p;
	L = (linkedList*)malloc(sizeof(linkedList));
	L->head = NULL;
	L->length = 0;
	L->comp = NULL;

	printf("(1)공백리스트 생성하기\n");

	// Fill your code
	displayList(L);
	printf("리스트에 저장된 데이터 개수:%d\n", getLength(L));

	setSortRule(L, whoIsPrecede);	// 리스트의 정렬 기준이 되는 함수 등록

	printf("\n(2)리스트에 10, 80, 50 노드를 삽입하되 내림차순으로 들어가도록 하기\n");

	// Fill your code (sortInsert() 연산 이용)
	sortInsert(L, 10);
	sortInsert(L, 80);
	
	sortInsert(L, 50);

	displayList(L);
	printf("리스트에 저장된 데이터 개수:%d\n", getLength(L));


	printf("\n(3)리스트에서 50 노드 탐색하기\n");

	// Fill your code (SLinkedListMain.c 와 동일)
	if(NULL!=search(L, 50)) printf("50노드를 찾았습니다\n");

	printf("\n(4)40 노드 삽입하기(내림차순)\n");
	// Fill your code (sortInsert() 연산 이용)
	sortInsert(L, 40);
	displayList(L);
	printf("리스트에 저장된 데이터 개수:%d\n", getLength(L));

	printf("\n(5)리스트에서 50 노드 삭제하기\n");

	// Fill your code (SLinkedListMain.c 와 동일)
	listNode*u=search(L, 50);
	delete(L,u);
	displayList(L);
	printf("리스트에 저장된 데이터 개수:%d\n", getLength(L));

	clear(L);

	return 0;
}
