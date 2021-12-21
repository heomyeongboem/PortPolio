#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

// ���� �� ����, create a empty heap
Heap* createHeap() {
	Heap* h = (Heap*)malloc(sizeof(Heap));
	h->numOfData = 0;
	h->heap[0] = 0;
	return h;
}

// ���� �������� �˻�, check if heap is empty			
int isEmpty(Heap* h) {
	return h->numOfData == 0 ? TRUE : FALSE;
}

// ���� ������ ��ġ�� ���� x ����, insert element x in appropriate position on heap
void insertHeap(Heap* h, HData x) {
	if (h->numOfData == MAX_SIZE) {//�� �� ���� �� ��
		printf("ERROR: Heap is FULL!!\n");
		return;
	}

	// Fill your code 


	int idx = h->numOfData+1;

	if (idx==1) {//�� ���� ������ 0���� ��(�������)�� numOfData�� 0�� �� �۵�
		h->heap[idx] = x;
		h->numOfData++;
		return 0;
	}

	 
		while (idx != 1) {//�� ���ΰ����� 1�� �̻��� �� numofData�� 1�̻��� �� �۵�
			if (x < h->heap[idx / 2])//1)���� �θ��尡 �ڽĳ�庸�� ū ��� �ڽĳ�� �ε����� �θ��尪�� ���� �� 
			{
				h->heap[idx] = h->heap[idx / 2];
				idx = idx / 2;
			}
			else {//2)���� �θ��尡 �ڽĳ�庸�� ���� ��� ���� �ε����� ���� ������ ���� ���� �׸��� return 0�� �־� �� �Լ��� �ٷ� �����ϰ� �����. �� ����ó���� �����ϴ��� �����ɷȽ��ϴ�.
				h->heap[idx] = x;
				h->numOfData++;
				return 0;
			}
			}
		h->heap[idx] = x;//1)�� �۵��� �۵�
		h->numOfData++;
	}

	
	




// ������ Ű ���� ���� ���� ���� �����ϰ� ��ȯ, delete the element with the smallest key value from the heap and return it
HData deleteHeap(Heap* h) {
	if (isEmpty(h)) {
		printf("ERROR: Heap is EMPTY!!\n");
		return 0;
	}

	HData item = h->heap[1];
	HData lastVal = h->heap[h->numOfData];
	int parentIdx = 1;
	int childIdx = 2;

	// Fill your code
	
	while (childIdx <= h->numOfData) {
		if ((childIdx < h->numOfData) && (h->heap[childIdx] > h->heap[childIdx + 1])) childIdx++;//���� ����Ʈ���� ��Ʈ���� ������ ����Ʈ���� ��Ʈ ��� ���� �� �ؼ� ������ ���� Ʈ������ �� ���� ��� childidx++�� 
		//�������ֹǷν� ������ ���� ���� ���ش�.
		if (lastVal < h->heap[childIdx])return 0;//������ ��带 �ٷ� �Ʒ� �����Ʈ����� �� ���� ���� �������� ������ ��� ���� �� ������ ����
		else {
			h->heap[parentIdx] = h->heap[childIdx];//�����Ʈ��尡 �� ���� ��� ���� �����Ʈ��带 �θ���� �Ű��ְ� 
			parentIdx = childIdx;//�� ���� ����Ͽ� ������ ��尡 �� ���� ����Ʈ���� ��Ʈ�� �̵��� �� �ְ� ����
			childIdx = childIdx * 2;//���������� �� ���� ����Ͽ� �ڽ� ��� ���� ��ġ�� �� �� �ְ� ��
		}

	}
	h->heap[parentIdx] = lastVal;//���� while ����  ���Ͽ� ������ ����� ������ ��ġ�� �˰� �Ǿ ������ ��ġ�� �̵������ش�.
	h->numOfData--;//������ ���� ���ش�. ��Ʈ��� �ϳ��� �����Ǿ����Ƿ� �´� ����
	return item;//������ ��Ʈ����� ���� ��ȯ

}

// �θ� ����� �ε��� �� ��ȯ, returns the index value of the parent node
int getParentIdx(int idx) {
	return idx / 2;
}

// ���� �ڽ� ����� �ε��� �� ��ȯ, returns index value of left child node
int getLChildIdx(int idx) {
	return idx * 2;
}

// ������ �ڽ� ����� �ε��� �� ��ȯ, returns index value of right chlid node		
int getRChildIdx(int idx) {
	return idx * 2 + 1;
}

void displayHeap(Heap* h) {
	int i;
	for (i = 1; i <= h->numOfData; i++)
		printf("%d %d\n", i, h->heap[i]);
	printf("\n");
}
