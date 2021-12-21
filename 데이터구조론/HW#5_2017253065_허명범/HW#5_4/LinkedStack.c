#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

// ���齺�� ����, create a empty stack
Stack* create() {

	// Fill your code
	Stack* S = malloc(sizeof(Stack));
	S->top = NULL;
	return S;

}

// ������ ��ȭ�������� Ȯ���ϴ� ����, operations to determine if the stack is full					
int isFull(Stack* S) {

	// Fill your code
	return 0;

}

// ������ ����������� Ȯ���ϴ� ����, operations to determine if the stack is empty			
int isEmpty(Stack* S) {

	// Fill your code
	return S->top == NULL;

}

// ������ top�� ��Ҹ� �߰��ϴ� ����, operation to add elements to the top of a stack			
void push(Stack* S, element x) {

	// Fill your code
	stackNode* newnode = (stackNode*)malloc(sizeof(stackNode));
	newnode->data = x;
	newnode->link = S->top;
	S->top = newnode;

}

// ���ÿ��� �������� ����� ��� ���� �� ��ȯ�ϴ� ����, operations that delete and return the last stored element in the stack
element pop(Stack* S) {

	// Fill your code
	stackNode* temp;
	element e;
	if (isEmpty(S)) {
		//printf("[ERROR] stack is Empty");
		return 0;
	}
	temp = S->top;
	e = temp->data;
	S->top = temp->link;
	free(temp);
	return e;

}

// ���ÿ��� �������� ����� ��Ҹ� ��ȯ�ϴ� ����, operations that return the last stored element in the stack			
element peek(Stack* S) {

	// Fill your code
	stackNode* e;
	if (isEmpty(S)) {
		//printf("[ERROR] stack is Empty");
		return 0;
	}

	else
		e = S->top;
	return e->data;
	
	//return S->top->data;

}

// ������ ��� ��� ���, display all elements in the stack 			
void displayStack(Stack* S) {
	stackNode* p = S->top;
	printf("STACK [ ");
	while (p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf(" ]\n");
}

// ���� ����, empty stack
void clear(Stack* S) {

	// Fill your code
	stackNode* temp;


	while (S->top != NULL) {
		temp = S->top;
		S->top = temp->link;
		free(temp);
	}

}

