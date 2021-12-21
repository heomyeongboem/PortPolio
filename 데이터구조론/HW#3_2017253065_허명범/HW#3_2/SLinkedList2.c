#include <stdio.h>
#include <stdlib.h>
#include "SLinkedList2.h"

linkedList* initList() {
	linkedList* L;
	L = (linkedList*)malloc(sizeof(linkedList));
	L->head = NULL;
	L->length = 0;
	return L;
}

int getLength(linkedList* L) {		// SLinkedList.c�� ����

	// Fill your code
	return L->length;

}

void insert(linkedList* L, listNode* pre, element x) {	// SLinkedList.c�� ����
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));

	// Fill your code (�� ��忡 ������ ����), input data to new node

	newNode->data = x;
	
	// Fill your code (ù ��° ���� ���ԵǴ� ���), input first node
	if (L->head == NULL) {
		newNode->link = NULL;
		L->head = newNode;
	}

	else if (pre == NULL) {
		newNode->link = L->head;
		L->head = newNode;
	}

	// Fill your code (�߰� ���� ���ԵǴ� ���), input middle node
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}

	// Fill your code (������ ���� ����), increased number of data
	L->length++;

}

void insertFirst(linkedList* L, element x) {	// SLinkedList.c�� ����
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));

	// Fill your code
	newNode->data = x;
	newNode->link = L->head;
	L->head = newNode;
	L->length++;

}

void insertLast(linkedList* L, element x) {	// SLinkedList.c�� ����
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode));

	// Fill your code
	newNode->data = x;
	newNode->link = NULL;



	if (L->head == NULL) L->head = newNode;
	else {
		listNode* temp = L->head;
		while (temp->link != NULL)
		{
			temp = temp->link;
		}
		temp->link = newNode;
	}
	L->length++;


}

int delete(linkedList* L, listNode* p) {		// SLinkedList.c�� ����
	listNode* pre;

	// Fill your code (���� ����Ʈ�� ���)
	if (L->head == NULL)return FALSE;

	// Fill your code (������ ��尡 ���� ���), if 
	if (p == NULL) return FALSE;

	// Fill your code (ù ��° ��尡 ������ ����� ���), if first node is deleted node
	if (L->head == p) {
		L->head = p->link;
		free(p);
		printf("��� ���� ����!\n");
	}

	// Fill your code (�� �̿��� ���), else~
	else {
		pre = L->head;
		while (pre->link != p) {
			pre = pre->link;
			if (pre == NULL)return FALSE;
		}
		pre->link = p->link;
		free(p);
		printf("��� ���� ����!\n");
	}

	// Fill your code (������ ���� ����), decreased number of data
	L->length--;
	return TRUE;

}

listNode* search(linkedList* L, element x) {	// SLinkedList.c�� ����
	listNode* temp = L->head;

	// Fill your code
	while (temp != NULL) {
		if (temp->data == x) {

			return temp;
		}
		else temp = temp->link;
	}
	return NULL;

}

void displayList(linkedList* L) {
	listNode* p;
	printf("L=(");
	p = L->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->link;
		if (p != NULL) printf(", ");
	}
	printf(")\n");
}

void clear(linkedList* L) {
	listNode* p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}

void reverse(linkedList* L) {

	// Fill your code
	listNode* p, *t, *r;
	p = L->head;
	t = NULL;
	r = NULL;
	
	while (p != NULL) {
		r = t;
		t = p;
		p = p->link;
		t->link = r;
	
	}

	L->head=t;
}
