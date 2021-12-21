#pragma once
#ifndef __HEAP_H__
#define __HEAP_H__

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100

typedef int HData;

typedef struct {
	HData heap[MAX_SIZE];
	int numOfData;
}Heap;

Heap* createHeap();					// ���� �� ����, create a empty heap
int isEmpty(Heap* h);				// ���� �������� �˻�, check if heap is empty
void insertHeap(Heap* h, HData x);	// ���� ������ ��ġ�� ���� x ����, insert element x in appropriate position on heap
HData deleteHeap(Heap* h);			// ������ Ű ���� ���� ���� ���� �����ϰ� ��ȯ, delete the element with the smallest key value from the heap and return it

int getParentIdx(int idx);			// �θ� ����� �ε��� �� ��ȯ, returns the index value of the parent node
int getLChildIdx(int idx);			// ���� �ڽ� ����� �ε��� �� ��ȯ, returns index value of left child node
int getRChildIdx(int idx);			// ������ �ڽ� ����� �ε��� �� ��ȯ, returns index value of right chlid node
void displayHeap(Heap* h);

#endif

