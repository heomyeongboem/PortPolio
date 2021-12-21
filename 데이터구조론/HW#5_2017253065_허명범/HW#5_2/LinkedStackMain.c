#include <stdio.h>
#include "LinkedStack.h"

int main() {
	Stack* S;
	element item;
	int i;

	printf("\n(1) ���� ���� �����ϱ�\n");	// (1) To create a empty stack

	// Fill your code
	S = create();
	displayStack(S);

	printf("\n(2) ���ÿ� 10, 20�� ���ʷ� ����\n");	// (2) Insert 10, 20 into the stack in order

	// Fill your code
	push(S, 10);
	displayStack(S);
	push(S, 20);
	displayStack(S);

	printf("\n(3) ���� top�� ��Ҹ� ���\n");	// (3) displays elements of the current top

	// Fill your code	// Elements stored in top: 
	if (isEmpty(S)) {
		printf("[ERROR] Stack is Empty!!");
	}
	else {
	printf("top�� ����� ���: %d\n",peek(S));
	}
	

	printf("\n(4) ���ÿ��� ��� ����\n");	// (4) Deleting an element from the stack

	// Fill your code	// elimination
	if (isEmpty(S)) {
		printf("[ERROR] Stack is Empty!!\n");
	}
	printf("%d ����\n",pop(S));
	displayStack(S);

	printf("\n(5) ���ÿ��� ��� ����\n");	// (5) Deleting an element from the stack

	// Fill your code	// elimination
	if (isEmpty(S)) {
		printf("[ERROR] Stack is Empty!!\n");
	}
	else { 
		printf("%d ����\n", pop(S)); 
	}
	displayStack(S);
	

	printf("\n(6) ���ÿ��� ��� ����\n");	// (6) Deleting an element from the stack
	 
	// Fill your code
	if (isEmpty(S)) {
		printf("[ERROR] Stack is Empty!!\n");
	}
	else { 
		printf("%d ����\n", pop(S)); 
	}
	displayStack(S);

	printf("\n(7) ���ÿ� 1���� 10���� �ڿ����� ���ʷ� ����\n");	// (7) Insert natural numbers from 1 to 10 into the stack in order

	// Fill your code
	for (i = 1; i < 11; i++) {
		push(S, i);
	}
	displayStack(S);
	

	printf("\n(8) ���� ����\n");	// (8) Empty stack

	// Fill your code
	clear(S);
	displayStack(S);
	return 0;
}

