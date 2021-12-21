#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

// 공백큐 생성, create s empty queue
Queue* createQueue() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}

// 큐가 공백상태인지 확인하는 연산, operations to determine if a queue is empty	
int isEmptyQueue(Queue* Q) {

	// Fill your code
	return Q->front == NULL;

}

// 큐의 rear에 요소를 추가하는 연산, operations that add elements to the rear of a queue
void enqueue(Queue* Q, element x) {

	// Fill your code
	queueNode* newnode = malloc(sizeof(queueNode));
	newnode->data = x;
	newnode->link = NULL;

	if (isEmptyQueue(Q))Q->front = newnode;
	else {
		Q->rear->link = newnode;
	}
	Q->rear = newnode;
}

// 큐에서 가장 먼저 저장된 요소 삭제 및 반환하는 연산, operations that delete and return the first stored element in a queue
element dequeue(Queue* Q) {

	// Fill your code
	if (isEmptyQueue(Q))return ERROR;
	else {
		queueNode* temp=Q->front;
		element e = temp->data;
		Q->front = temp->link;
		if (Q->front == NULL)Q->rear = NULL;
		return e;
	
	}
}

// 큐 비우기, empth queue		
void clearQueue(Queue* Q) {
	queueNode* p;
	while (Q->front) {
		p = Q->front;
		Q->front = Q->front->link;
		free(p);
		p = NULL;
	}
}