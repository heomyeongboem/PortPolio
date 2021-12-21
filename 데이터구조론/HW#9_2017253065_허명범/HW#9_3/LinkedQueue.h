#pragma once
#ifndef __LINKED_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

#define ERROR 123456789
#define TRUE 1
#define FALSE 0

typedef int element;

// Queue�� ��� ������ ����ü�� ����, define the node structure in queue as a structure
typedef struct QueueNode {
	element data;
	struct QueueNode* link;
}queueNode;

// Queue�� front, rear�� ǥ���� ����ü, the structure that whill represent the front, rear of the queue
typedef struct LinkedQueue {
	queueNode* front, * rear;
}Queue;

Queue* createQueue();				// ����ť ����, create s empty queue
int isEmptyQueue(Queue* Q);			// ť�� ����������� Ȯ���ϴ� ����, operations to determine if a queue is empty
void enqueue(Queue* Q, element x);	// ť�� rear�� ��Ҹ� �߰��ϴ� ����, operations that add elements to the rear of a queue
element dequeue(Queue* Q);			// ť���� ���� ���� ����� ��� ���� �� ��ȯ�ϴ� ����, operations that delete and return the first stored element in a queue
void clearQueue(Queue* Q);			// ť ����, empth queue

#endif

