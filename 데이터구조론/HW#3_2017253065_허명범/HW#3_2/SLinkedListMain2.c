#include <stdio.h>
#include "SLinkedList.h"
#include<malloc.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
//�ֽ� c���ϰ� pdf ������ ��� ������ �޶� c������ �������� �Ͽ����ϴ�.
int main() {
	linkedList* L;
	listNode* p;

	L = (linkedList*)malloc(sizeof(linkedList));
	L->head = NULL;
	L->length = 0;

	printf("(1)���鸮��Ʈ �����ϱ�\n");

	// Fill your code
	displayList(L);
	printf("����Ʈ�� ����� ������ ����:%d\n", getLength(L));


	printf("\n(2)����Ʈ�� ��, ȭ, �� ��带 ������� �����ϱ�\n");

	// Fill your code

	char* s1 = {"��"};
	char* y = { "ȭ" };
	char* z = { "��" };
	
	insertLast(L, s1);
	insertLast(L, y);
	insertLast(L, z);
	displayList(L);
	printf("����Ʈ�� ����� ������ ����:%d\n", getLength(L));
	
	printf("\n(3)�� ��� �ڿ� �� ��� �����ϱ�\n");

	// Fill your code
	char* s2 = {"��"};
	linkedList* k = search(L,z);
	insert(L, k, s2);
	displayList(L);
	printf("����Ʈ�� ����� ������ ����:%d\n", getLength(L));

	printf("\n(4)����Ʈ���� �� ��� Ž���ϱ�\n");
	char s3 = { "��" };
	// Fill your code
	if(NULL==search(L,s3))printf("ã�� �����Ͱ� �����ϴ�.\n");



	printf("\n(5)����Ʈ ������ �������� �ٲٱ�\n");

	// Fill your code
	reverse(L);
	displayList(L);
	printf("����Ʈ�� ����� ������ ����:%d\n", getLength(L));

	clear(L);

	return 0;
}
