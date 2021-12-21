#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

// ����ť ����, create s empty queue
Queue* createQueue() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}

// ť�� ����������� Ȯ���ϴ� ����, operations to determine if a queue is empty	
int isEmptyQueue(Queue* Q) {

	// Fill your code
	return Q->front == NULL;

}

// ť�� rear�� ��Ҹ� �߰��ϴ� ����, operations that add elements to the rear of a queue
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

// ť���� ���� ���� ����� ��� ���� �� ��ȯ�ϴ� ����, operations that delete and return the first stored element in a queue
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

// ť ����, empth queue		
void clearQueue(Queue* Q) {
	queueNode* p;
	while (Q->front) {
		p = Q->front;
		Q->front = Q->front->link;
		free(p);
		p = NULL;
	}
}