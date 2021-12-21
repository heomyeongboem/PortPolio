#pragma once
#ifndef __ARRAY_STACK_H__
#define __ARRAY_STACK_H__

#define MAX_SIZE 100
#define ERROR 123456789
#define TRUE 1
#define FALSE 0

typedef int element;

// Stack�� ����ü�� ����, define stack as a structure
typedef struct ArrayStack {
	element stack[MAX_SIZE];
	 int top;
}Stack;

Stack* create();					// ���齺�� ����, create a empty stack
int isFull(Stack* S);				// ������ ��ȭ�������� Ȯ���ϴ� ����, operations to determine if the stack is full
int isEmpty(Stack* S);				// ������ ����������� Ȯ���ϴ� ����, operations to determine if the stack is empty
void push(Stack* S, element x);		// ������ top�� ��Ҹ� �߰��ϴ� ����, operations to add elements to the top of a stack
element pop(Stack* S);				// ���ÿ��� �������� ����� ��� ���� �� ��ȯ�ϴ� ����, operations that delete and return the last stored element in the stack
element peek(Stack* S);				// ���ÿ��� �������� ����� ��Ҹ� ��ȯ�ϴ� ����, operations that return the last stored element in the stack
void displayStack(Stack* S);		// ������ ��� ��� ���, display all elements in the stack
void clear(Stack* S);				// ���� ����, empty stack

#endif

