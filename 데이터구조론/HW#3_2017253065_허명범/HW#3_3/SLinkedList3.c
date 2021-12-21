#include <stdio.h>
#include <stdlib.h>
#include "SLinkedList3.h"

linkedList* initList() {
	linkedList* L;
	L = (linkedList*)malloc(sizeof(linkedList));
	L->head = NULL;
	L->length = 0;
	L->comp = NULL;
	return L;
}

int getLength(linkedList* L) {		// SLinkedList.c�� ����

	// Fill your code
	return L->length;

}

void displayList(linkedList* L) {
	listNode* p;
	printf("L=(");
	p = L->head;
	while (p != NULL) {
		printf("%d", p->data);
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


void setSortRule(linkedList* L, int (*comp)(element d1, element d2)) {
	L->comp = comp;		// ����Ʈ�� ��� comp�� �ʱ�ȭ
}

void sortInsert(linkedList* L, element x) {

	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;

	
	// Fill your code (ù ��° ���� ���ԵǴ� ���), input first node
	//���� ����Ʈ
	if (L->head == NULL) {
		newNode->link = NULL;
		L->head = newNode;
	}
	//ù��°��庸�� ���� ���� Ŀ�� ù��° ���� ���ԉ�
	else if (x > L->head->data) 
	{
		newNode->link = L->head;
		L->head = newNode;
	}
	

	// Fill your code (���鸮��Ʈ�� �ƴ� ��� ���� ���ؿ� ���� ���� ���� ��ġ ã�Ƽ� ����)

	//��� �����Ҳ��� 1st ��ġ�� ��ȯ 2nd  ���� 
	else if (L->head != NULL)
	{
	listNode* p = L->head;
	listNode* p_prev = NULL;

	while (NULL != p && x < p->data) {
		p_prev = p;
		p = p->link;
	}
	newNode->link = p_prev->link;
	p_prev->link = newNode;
	}
	




	/*
	//ó���� �ִ� ���(newNode�� �����Ͱ� ù��° ����� �����ͺ��� ū ���)
	else if (newNode->data > L->head->data) {
		newNode->link = L->head;
		L->head = newNode;

	}

	//�߰��� �ִ� ���
	else if (newNode->data < L->head->data) {
		listNode* temp = L->head;

		while (temp->link != NULL) {
			if (newNode->data < temp->data)
			{
				newNode->link = temp->link;
				temp->link = newNode;
				break;
			}
			else temp = temp->link;
		}
		*/
		// Fill your code (������ ���� ����)

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