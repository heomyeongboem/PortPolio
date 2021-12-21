#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

// ���齺�� ����, create empty stack
Stack* createStack() {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S->top = -1;
	return S;
}

// ������ ��ȭ�������� Ȯ���ϴ� ����, operations to determine if the stack is full					
int isFullStack(Stack* S) {
	return S->top == MAX_STACK_SIZE - 1;
}

// ������ ����������� Ȯ���ϴ� ����, operations to determine if the stack is empty		
int isEmptyStack(Stack* S) {
	return S->top == -1;
}

// ������ top�� ��Ҹ� �߰��ϴ� ����, operations that add elements to top of stack		
void push(Stack* S, element x) {
	if (isFullStack(S)) {
		printf("Stack is FULL!!\n");
		return;
	}
	else
		S->stack[++(S->top)] = x;
}

// ���ÿ��� �������� ����� ��� ���� �� ��ȯ�ϴ� ����, operations that delete and return the last stored element in a stack
element pop(Stack* S) {
	if (isEmptyStack(S)) {
		printf("[ERROR] Stack is EMPTY!!\n");
		return ERROR;
	}
	else
		return S->stack[(S->top)--];
}

// ���ÿ��� �������� ����� ��Ҹ� ��ȯ�ϴ� ����, operations that return the last stored element in the stack		
element peek(Stack* S) {
	if (isEmptyStack(S)) {
		printf("[ERROR] Stack is EMPTY!!\n");
		return ERROR;
	}
	else
		return S->stack[S->top];
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
void clearStack(Stack* S) {
	S->top = -1;
}