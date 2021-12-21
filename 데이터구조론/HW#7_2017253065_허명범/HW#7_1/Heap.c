#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

// 공백 힙 생성, create a empty heap
Heap* createHeap() {
	Heap* h = (Heap*)malloc(sizeof(Heap));
	h->numOfData = 0;
	h->heap[0] = 0;
	return h;
}

// 힙이 공백인지 검사, check if heap is empty			
int isEmpty(Heap* h) {
	return h->numOfData == 0 ? TRUE : FALSE;
}

// 힙의 적당한 위치에 원소 x 삽입, insert element x in appropriate position on heap
void insertHeap(Heap* h, HData x) {
	if (h->numOfData == MAX_SIZE) {//꽉 찬 상태 일 때
		printf("ERROR: Heap is FULL!!\n");
		return;
	}

	// Fill your code 


	int idx = h->numOfData+1;

	if (idx==1) {//힙 내부 갯수가 0개일 때(공백상태)로 numOfData가 0일 때 작동
		h->heap[idx] = x;
		h->numOfData++;
		return 0;
	}

	 
		while (idx != 1) {//힙 내부갯수가 1개 이상일 때 numofData가 1이상일 때 작동
			if (x < h->heap[idx / 2])//1)만일 부모노드가 자식노드보다 큰 경우 자식노드 인덱스에 부모노드값을 저장 후 
			{
				h->heap[idx] = h->heap[idx / 2];
				idx = idx / 2;
			}
			else {//2)만일 부모노드가 자식노드보다 작은 경우 원래 인덱스에 새로 삽입한 값을 저장 그리고 return 0을 넣어 이 함수가 바로 종료하게 만든다. 이 예외처리를 생각하느라 오래걸렸습니다.
				h->heap[idx] = x;
				h->numOfData++;
				return 0;
			}
			}
		h->heap[idx] = x;//1)식 작동시 작동
		h->numOfData++;
	}

	
	




// 힙에서 키 값이 가장 작은 원소 삭제하고 반환, delete the element with the smallest key value from the heap and return it
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
		if ((childIdx < h->numOfData) && (h->heap[childIdx] > h->heap[childIdx + 1])) childIdx++;//왼쪽 서브트리의 루트노드와 오른쪽 서브트리의 루트 노드 값을 비교 해서 오른쪽 서브 트리값이 더 작은 경우 childidx++를 
		//실행해주므로써 오른쪽 노드로 가게 해준다.
		if (lastVal < h->heap[childIdx])return 0;//마지막 노드를 바로 아래 서브루트노드중 더 작은 노드와 비교했을때 마지막 노드 값이 더 작으면 종료
		else {
			h->heap[parentIdx] = h->heap[childIdx];//서브루트노드가 더 작은 경우 비교한 서브루트노드를 부모노드로 옮겨주고 
			parentIdx = childIdx;//이 식을 사용하여 마지막 노드가 그 다음 서브트리의 루트로 이동할 수 있게 해줌
			childIdx = childIdx * 2;//마지막으로 이 식을 사용하여 자식 노드 값이 위치를 알 수 있게 됌
		}

	}
	h->heap[parentIdx] = lastVal;//위에 while 문을  통하여 마지막 노드의 적절한 위치를 알게 되어서 적절한 위치로 이동시켜준다.
	h->numOfData--;//갯수를 삭제 해준다. 루트노드 하나가 삭제되었으므로 맞는 수순
	return item;//삭제된 루트노드의 값을 반환

}

// 부모 노드의 인덱스 값 반환, returns the index value of the parent node
int getParentIdx(int idx) {
	return idx / 2;
}

// 왼쪽 자식 노드의 인덱스 값 반환, returns index value of left child node
int getLChildIdx(int idx) {
	return idx * 2;
}

// 오른쪽 자식 노드의 인덱스 값 반환, returns index value of right chlid node		
int getRChildIdx(int idx) {
	return idx * 2 + 1;
}

void displayHeap(Heap* h) {
	int i;
	for (i = 1; i <= h->numOfData; i++)
		printf("%d %d\n", i, h->heap[i]);
	printf("\n");
}
