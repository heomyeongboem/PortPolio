#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

linkedList* initList() {
	linkedList* L;
	L = (linkedList*)malloc(sizeof(linkedList));
	L->head = NULL;
	L->length = 0;
	return L;
}

int getLength(linkedList* L) {
	return L->length;
}


void insert(linkedList* L, listNode* pre, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;

	// Fill your code
	//공백리스트인 경우


	if (L->head==NULL) {
		newNode->llink = NULL;
		newNode->rlink = NULL;
		L->head = newNode;
	}

	//맨첫번째 삽입 되는 경우
	else if (pre == NULL) {
		newNode->llink = NULL;
		newNode->rlink = L->head;
		L->head = newNode;
		newNode->rlink->llink = newNode;
	}
	//중간에 삽입 되는 경우
	else {
		newNode->rlink = pre->rlink;
		pre->rlink = newNode;
		newNode->llink = pre;
		//뒤에 노드가 있는 경우
		if (newNode->rlink != NULL) {
			newNode->rlink->llink = newNode;
		}

	}

	L->length++;
}

void insertFirst(linkedList* L, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;

	// Fill your code
	//공백리스트인 경우
	if (L->head == NULL) {
		newNode->llink = NULL;
		newNode->rlink = NULL;
		L->head = newNode;
	}
	//나머지인 경우
	else {
		newNode->llink = NULL;
		newNode->rlink = L->head;
		L->head = newNode;
		newNode->rlink->llink = newNode;
	}
	L->length++;
}

void insertLast(linkedList* L, element x) {
	listNode* newNode, * temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;

	// Fill your code
	
	newNode->rlink = NULL;//공통
	
	//공백리스트인 경우
	if (L->head == NULL) {
		newNode->llink = NULL;
		newNode->rlink = NULL;
		L->head = newNode;
	}
	//나머지인 경우
	else {
		temp = L->head;
		while (temp->rlink != NULL) {
			temp = temp->rlink;
		}
		temp->rlink = newNode;
		newNode->llink = temp;
	}
	L->length++;
}

int deleteNode(linkedList* L, listNode* p) {

	// Fill your code
	//공백리스트인 경우
	if (L->head == NULL) return FALSE;
	//삭제할 노드가 없는 경우
	if (p == NULL) return FALSE;
	//첫번째 노드를 삭제 하는 경우
	if (p->llink == NULL) {
		L->head = p->rlink;
		p->rlink->llink = NULL;
	}
	//마지막 노드를 삭제 하는 경우
	if (p->rlink == NULL) {
		p->llink->rlink = NULL;
	}
	//중간 노드를 삭제 하는 경우 나머지를 의미한다
	else {
		p->llink->rlink = p->rlink;
		p->rlink->llink = p->llink;
	}
	free (p);
	L->length--;
	return TRUE;
}

listNode* search(linkedList* L, element x) {
	listNode* temp = L->head;

	while (temp != NULL) {
		if (temp->data == x)
			return temp;
		else
			temp = temp->rlink;
	}
	return temp;
}

void displayList(linkedList* L) {
	listNode* p;
	printf("L=(");
	p = L->head;
	while (p != NULL) {
		printf("%d", p->data);
		p = p->rlink;
		if (p != NULL) printf(", ");
	}
	printf(")\n");
}

void clear(linkedList* L) {
	listNode* p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->rlink;
		free(p);
		p = NULL;
	}
}

