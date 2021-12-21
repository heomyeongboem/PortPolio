#include <stdio.h>
#include "DLinkedList.h"

int main(){
	linkedList* L;
	listNode* p;
	
	printf("(1)���� ���� ����Ʈ �����ϱ�\n");	// (1)To create a doubly linked list
	L = initList();
	displayList(L);
	printf("����Ʈ�� ����� ������ ����: %d\n", getLength(L));	// Number of data stored in the list
	
	printf("\n(2)����Ʈ�� 10 ��带 ù ��° ���� �����ϱ�\n");	// (2)Inserting 10 node into the list as the first node
	insertFirst(L, 10);
	displayList(L);
	printf("����Ʈ�� ����� ������ ����: %d\n", getLength(L));	// Number of data stored in the list
	
	printf("\n(3)����Ʈ�� 50 ��带 ������ ���� �����ϱ�\n");	// (3)Inserting 50 node into the list as the last node
	insertLast(L, 50);
	displayList(L);
	printf("����Ʈ�� ����� ������ ����: %d\n", getLength(L));	// Number of data stored in the list
	
	printf("\n(4)����Ʈ�� 50 ��� �ڿ� 80 ��带 �����ϱ�\n");	// (4)Insert 80 node after 50 node in the list
	p = search(L, 50);
	insert(L, p, 80);
	displayList(L);
	printf("����Ʈ�� ����� ������ ����: %d\n", getLength(L));	// Number of data stored in the list
	
	printf("\n(5)80 ��带 �˻��ϰ� �����ϱ�\n");	// (5)Search for and delete 80 node
	p = search(L, 80);
	if(p == NULL)
		printf("ã�� �����Ͱ� �����ϴ�.\n");	// No data
	else
		printf("%d ��带 ã�ҽ��ϴ�\n", p->data);	// Found node %d
	if(deleteNode(L, p))
		printf("��� ���� ����!\n");	// Delete node successful
	else
		printf("��� ���� ����!\n");	// Failed to delete node
	displayList(L);
	printf("����Ʈ�� ����� ������ ����: %d\n", getLength(L));	// Number of data stored in the lis
	
	printf("\n(6)10 ��� �ڿ� 30 ��� �����ϱ�\n");	// (6)Inserting 30 node after 10 node
	p = search(L, 10);
	insert(L, p, 30);
	displayList(L);
	printf("����Ʈ�� ����� ������ ����: %d\n", getLength(L));	// Number of data stored in the list
	
	printf("\n(7)5 ��带 �˻��ϰ� �����ϱ�\n");	// (7)To search for and delete 5 node
	p = search(L, 5);
	if (p == NULL)
		printf("ã�� �����Ͱ� �����ϴ�.\n");	// No data
	else
		printf("%d ��带 ã�ҽ��ϴ�\n", p->data);	// Found node %d
	if (deleteNode(L, p))
		printf("��� ���� ����!\n");	// Delete node successful
	else
		printf("��� ���� ����!\n");	// Failed to delete node
	displayList(L);
	printf("����Ʈ�� ����� ������ ����: %d\n", getLength(L));	// Number of data stored in the list
	
	return 0;
}

