#pragma once
#ifndef __ARRAY_STACK_H__
#define __ARRAY_STACK_H__

#define MAX_STACK_SIZE 10
#define ERROR 123456789
#define TRUE 1
#define FALSE 0

typedef int element;

// Stack�� ����ü�� ����, define stack as structure
typedef struct ArrayStack {
	element stack[MAX_STACK_SIZE];
	int top;
}Stack;

Stack* createStack();					// ���齺�� ����, create empty stack
int isFullStack(Stack* S);				// ������ ��ȭ�������� Ȯ���ϴ� ����, operations to determine if the stack is full
int isEmptyStack(Stack* S);				// ������ ����������� Ȯ���ϴ� ����, operations to determine if the stack is empty
void push(Stack* S, element x);			// ������ top�� ��Ҹ� �߰��ϴ� ����, operations that add elements to top of stack
element pop(Stack* S);					// ���ÿ��� �������� ����� ��� ���� �� ��ȯ�ϴ� ����, operations that delete and return the last stored element in a stack
element peek(Stack* S);					// ���ÿ��� �������� ����� ��Ҹ� ��ȯ�ϴ� ����, operations that return the last stored element in the stack
void displayStack(Stack* S);			// ������ ��� ��� ���, display all elements in the stack
void clearStack(Stack* S);				// ���� ����, empty stack

#endif
