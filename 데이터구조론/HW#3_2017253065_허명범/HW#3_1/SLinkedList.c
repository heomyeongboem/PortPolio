#include <stdio.h>
#include <stdlib.h>
#include "SLinkedList.h"


linkedList* initList() {
	linkedList* L;
	L = (linkedList*)malloc(sizeof(linkedList));
	L->head = NULL;
	L->length = 0;
	return L;
}

int getLength(linkedList* L) {

	// Fill your code
	return L->length;
	
}

void insert(linkedList* L, listNode* pre, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));

	// Fill your code (새 노드에 데이터 저장), input data to new node
	newNode->data = x;

	// Fill your code (첫 번째 노드로 삽입되는 경우), input first node
	if (L->head == NULL) {
		newNode->link = NULL;
		L->head = newNode;
	}

	else if (pre == NULL) {
		newNode->link = L->head;
		L->head = newNode;
	}

	// Fill your code (중간 노드로 삽입되는 경우), input middle node
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}

	// Fill your code (데이터 개수 증가), increased number of data
	L->length++;

}

void insertFirst(linkedList* L, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));

	// Fill your code
	newNode->link = L->head;
	L->head = newNode;
	L->length++;

}

void insertLast(linkedList* L, element x) {
	listNode* newNode;
	
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

int deleteNode(linkedList* L, listNode* p) {
	listNode* pre;

	// Fill your code (공백 리스트인 경우), if null list
	if (L->head == NULL)return FALSE;

	// Fill your code (삭제할 노드가 없는 경우), if 
	if (p == NULL) return FALSE;

	// Fill your code (첫 번째 노드가 삭제할 노드인 경우), if first node is deleted node
	if (L->head == p) {
		L->head = p->link;
		free (p);
		printf("노드 삭제 성공!\n");
	}

	// Fill your code (그 이외의 경우), else~
	else {
		pre = L->head;
		while (pre->link != p) {
			pre = pre->link;
			if (pre == NULL)return FALSE;
		}
		pre->link = p->link;
		free(p);
		printf("노드 삭제 성공!\n");
	}

	// Fill your code (데이터 개수 감소), decreased number of data
	L->length--;
	return TRUE;

}

int deleteData(linkedList* L, element x) {
	listNode* pre1;

	// Fill your code (공백 리스트인 경우), if null list
	if (L->head == NULL)return FALSE;
	// Fill your code (삭제할 노드가 없는 경우), if no nodes to delete
	listNode* k=search(L, x);
	if (k == NULL) return FALSE;
	// Fill your code (첫 번째 노드가 삭제할 노드인 경우), if first node is deleted node
	if (L->head == k) {
		L->head = k->link;
		free(k);
		printf("노드 삭제 성공!\n");
	}
	// Fill your code (그 이외의 경우), else
	else {
		pre1 = L->head;
		while (pre1->link != k) {
			pre1 = pre1->link;
			if (pre1 == NULL)return FALSE;
		}
		pre1->link = k->link;
		free(k);
		printf("노드 삭제 성공!\n");
	}

	// Fill your code (데이터 개수 감소), decreased number of data
	L->length--;
	return TRUE;
}


listNode* search(linkedList* L, element x) {
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