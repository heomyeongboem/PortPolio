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

	printf("(1)���鸮��Ʈ �����ϱ�\n");

	// Fill your code
	displayList(L);
	printf("����Ʈ�� ����� ������ ����:%d\n", getLength(L));

	setSortRule(L, whoIsPrecede);	// ����Ʈ�� ���� ������ �Ǵ� �Լ� ���

	printf("\n(2)����Ʈ�� 10, 80, 50 ��带 �����ϵ� ������������ ������ �ϱ�\n");

	// Fill your code (sortInsert() ���� �̿�)
	sortInsert(L, 10);
	sortInsert(L, 80);
	
	sortInsert(L, 50);

	displayList(L);
	printf("����Ʈ�� ����� ������ ����:%d\n", getLength(L));


	printf("\n(3)����Ʈ���� 50 ��� Ž���ϱ�\n");

	// Fill your code (SLinkedListMain.c �� ����)
	if(NULL!=search(L, 50)) printf("50��带 ã�ҽ��ϴ�\n");

	printf("\n(4)40 ��� �����ϱ�(��������)\n");
	// Fill your code (sortInsert() ���� �̿�)
	sortInsert(L, 40);
	displayList(L);
	printf("����Ʈ�� ����� ������ ����:%d\n", getLength(L));

	printf("\n(5)����Ʈ���� 50 ��� �����ϱ�\n");

	// Fill your code (SLinkedListMain.c �� ����)
	listNode*u=search(L, 50);
	delete(L,u);
	displayList(L);
	printf("����Ʈ�� ����� ������ ����:%d\n", getLength(L));

	clear(L);

	return 0;
}
