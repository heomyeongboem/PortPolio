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

int getLength(linkedList* L) {		// SLinkedList.c와 동일

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
	L->comp = comp;		// 리스트의 멤버 comp를 초기화
}

void sortInsert(linkedList* L, element x) {

	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;

	
	// Fill your code (첫 번째 노드로 삽입되는 경우), input first node
	//공백 리스트
	if (L->head == NULL) {
		newNode->link = NULL;
		L->head = newNode;
	}
	//첫번째노드보다 들어가는 값이 커서 첫번째 노드로 삽입됌
	else if (x > L->head->data) 
	{
		newNode->link = L->head;
		L->head = newNode;
	}
	

	// Fill your code (공백리스트가 아닌 경우 정렬 기준에 맞춰 들어가기 위한 위치 찾아서 삽입)

	//어디에 삽입할껀지 1st 위치를 반환 2nd  연결 
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
	//처음에 넣는 경우(newNode의 데이터가 첫번째 노드의 데이터보다 큰 경우)
	else if (newNode->data > L->head->data) {
		newNode->link = L->head;
		L->head = newNode;

	}

	//중간에 넣는 경우
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
		// Fill your code (데이터 개수 증가)

		L->length++;
	}

int delete(linkedList* L, listNode* p) {		// SLinkedList.c와 동일
	listNode* pre;

	// Fill your code (공백 리스트인 경우)
	if (L->head == NULL)return FALSE;

	// Fill your code (삭제할 노드가 없는 경우), if 
	if (p == NULL) return FALSE;

	// Fill your code (첫 번째 노드가 삭제할 노드인 경우), if first node is deleted node
	if (L->head == p) {
		L->head = p->link;
		free(p);
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

listNode* search(linkedList* L, element x) {	// SLinkedList.c와 동일
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