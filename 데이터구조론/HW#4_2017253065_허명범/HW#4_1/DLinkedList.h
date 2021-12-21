#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int element;

// ���߿��Ḯ��Ʈ�� ��� ������ ����ü�� ����, define the node structure of a doubly linked list as a structure
typedef struct ListNode {
	element data;
	struct ListNode *llink, *rlink;
}listNode;

// ����Ʈ ������ ��Ÿ���� head ��带 ����ü�� ����. define the head node as a structure indicating the beginning of the list
typedef struct LinkedList {
	listNode* head;
	int length;
}linkedList;

linkedList* initList();									// ���鸮��Ʈ ����, generate a blank list 
void insert(linkedList* L, listNode* pre, element x);	// �߰� ���� ����, insert as middle node 
void insertFirst(linkedList* L, element x);				// ù ��° ���� ����, insert as first node 
void insertLast(linkedList* L, element x);				// ������ ���� ����, insert as last node
int deleteNode(linkedList* L, listNode* p);				// ��� ����, delete node
listNode* search(linkedList* L, element x);				// �˻�, search
int getLength(linkedList* L);							// ����Ʈ�� ����Ǿ� �ִ� �������� �� ��ȯ, return the number of data stored in the list 
void displayList(linkedList* L);						// ����Ʈ�� ��� ��� ���, display all elements in the list
void clear(linkedList* L);								// ����Ʈ�� ��ü �޸� ����, release full memory of the list

#endif

