#include <stdio.h>
#include "SLinkedList.h"

int main() {
	linkedList* L;
	listNode* p;
	int length;

	//이걸 작성 안할 시, 초기화 되지 않은 지역변수 사용 불가라 떠서 initList()함수를 사용하지 않고 처음부터 제가 직접 초기화 시켜주었습니다.
	L = (linkedList*)malloc(sizeof(linkedList));
	L->head = NULL;
	L->length = 0;

	     printf("\n(1)공백리스트 생성하기\n");
	     //Fill your code
		
		 displayList(L);
		 printf("리스트에 저장된 데이터 개수:%d\n", getLength(L));
		

		 printf("\n(2)리스트에 10, 50 노드를 순서대로 삽입하기\n");
	//Fill your code
		insert(L,NULL,10);
		insertLast(L, 50);
		displayList(L);
		printf("리스트에 저장된 데이터 개수:%d\n",getLength(L));

		printf("\n(3)리스트에 마지막에 80 노드를 추가하기\n");
	//Fill your code
		insertLast(L, 80);
		displayList(L);
		printf("리스트에 저장된 데이터 개수:%d\n", getLength(L));

		printf("\n(4)리스트에서 50 노드 탐색하기\n");
    //Fill your code
		listNode* u = search(L,50);
		printf("%d 노드를 찾았습니다\n", u->data);

		printf("\n(5)50 노드 뒤에 60 노드 삽입하기\n");
	//Fill your code
		insert(L, u, 60);
		displayList(L);
		printf("리스트에 저장된 데이터 개수:%d\n", getLength(L));

		printf("\n(6)리스트에서 80 노드 삭제하기( node 사용 )\n");
	//Fill your code
		listNode* w= search(L, 80);
		deleteNode(L,w);
		displayList(L);
		printf("리스트에 저장된 데이터 개수:%d\n", getLength(L));

		printf("\n(7)리스트에서 50 노드 삭제하기( element 사용 )\n");
	//Fill your code
		deleteData(L, 50);
		displayList(L);
		printf("리스트에 저장된 데이터 개수:%d\n", getLength(L));

		clear(L);

	return 0;
}