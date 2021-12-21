#include <stdio.h>
#include "ArrayStack.h"

int main() {
	Stack* S;
	element item;
	int i;
	
	//S = (Stack*)malloc(sizeof(Stack));

	printf("\n(1) ���� ���� �����ϱ�\n");	// (1) To create a blank stack

	// Fill your code
	S=create();
	displayStack(S);

	printf("\n(2) ���ÿ� 10, 20�� ���ʷ� ����\n");	// (2) Insert 10, 20 into the stack in order

	// Fill your code
	
	push(S, 10);
	displayStack(S);
	push(S, 20);
	displayStack(S);

	printf("\n(3) ���� top�� ��Ҹ� ���\n");	// (3) Display elements of the current top

	// Fill your code	// Elements stored in top: 
	printf("top�� ����� ���:%d\n", peek(S));

	printf("\n(4) ���ÿ��� ��� ����\n");	// (4) Deleting an element from the stack

	// Fill your code	// elimination
	if(isEmpty(S))printf("[ERROR] Stack is Empty!!\n");
	else { printf("%d ����\n", pop(S)); }
	displayStack(S);

	printf("\n(5) ���ÿ��� ��� ����\n");	// (5) Deleting an element from the stack

	// Fill your code	// eliminaion
	if (isEmpty(S)) printf("[ERROR] Stack is Empty!!\n");
	else {
		printf("%d ����\n", pop(S));
	}
	
	displayStack(S);

	printf("\n(6) ���ÿ��� ��� ����\n");	// (6) Deleting an elment from the stack

	// Fill your code
	if (isEmpty(S)) printf("[ERROR] Stack is Empty!!\n");
	else {
	printf("%d ����\n", pop(S));
	}
	displayStack(S);

	printf("\n(7) ���ÿ� 1���� 10���� �ڿ����� ���ʷ� ����\n");	// (7) Insert natural numbers from 1 to 10 into the stack in oerder

	// Fill your code
	push(S, 1);
	push(S, 2);
	push(S, 3);
	push(S, 4);
	push(S, 5);
	push(S, 6);
	push(S, 7);
	push(S, 8);
	push(S, 9);
	push(S, 10);
	displayStack(S);

	printf("\n(8) ���� ����\n");	// (8) Empty stack

	// Fill your code
	clear(S);
	displayStack(S);

	return 0;
}
