#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

// ���齺�� ����, create a empty stack
Stack* create() {

	// Fill your code
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->top = -1;
	return s;

}

// ������ ��ȭ�������� Ȯ���ϴ� ����, operations to determine if the stack is full
int isFull(Stack* S) {

	// Fill your code
	return S->top == MAX_SIZE - 1;

}

// ������ ����������� Ȯ���ϴ� ����, operations to determine if the stack is empty			
int isEmpty(Stack* S) {

	// Fill your code
	return S->top == -1;

}

// ������ top�� ��Ҹ� �߰��ϴ� ����, operations to add elements to the top of a stack
void push(Stack* S, element x) {

	// Fill your code
	if (isFull(S)) {
		printf("[ERROR] Stack is FUll!!\n");
		return;
	}
	else {
		S->stack[++(S->top)] = x;
	}

}

// ���ÿ��� �������� ����� ��� ���� �� ��ȯ�ϴ� ����, operations that delete and return the last stored element in the stack	
element pop(Stack* S) {

	// Fill your code
	if (isEmpty(S)) {
		//printf("[ERROR] Stack is Empty!!\n");
		return ERROR;
	}
	else
	{
		return S->stack[(S->top)--];
	}

}

// ���ÿ��� �������� ����� ��Ҹ� ��ȯ�ϴ� ����, operations that return the last stored element in the stack
element peek(Stack* S) {

	// Fill your code
	if (isEmpty(S))
	{
		printf("[ERROR] Stack is Empty!!\n");
		return ERROR;
	}
	else {
		return S->stack[(S->top)];
	}

}

// ������ ��� ��� ���, display all elements in the stack
void displayStack(Stack* S) {
	int i;
	printf("STACK [ ");
	for (i = 0; i <= S->top; i++)
		printf("%d ", S->stack[i]);
	printf(" ]\ttop: %d\n", S->top);
}

// ���� ����, empty stack
void clear(Stack* S) {

	// Fill your code

	S->top = -1;
}

