#pragma once
#ifndef __LINKED_STACK_H__
#define __LINKED_STACK_H__

#define ERROR 123456789
#define TRUE 1
#define FALSE 0

typedef int element;

// Stack�� ��� ������ ����ü�� ����, define stack's node structure as a structure
typedef struct StackNode {
	element data;
	struct StackNode* link;
}stackNode;

// Stack�� ������ ���(���� �ֱٿ� ���Ե� ���)�� ��Ÿ���� top�� ����ü�� ����, define a top as a structure that represents the last element of stack ( most recently inserted node ) 
typedef struct LinkedStack {
	stackNode* top;
}Stack;

Stack* create();					// ���齺�� ����, create a empty stack
int isEmpty(Stack* S);				// ������ ����������� Ȯ���ϴ� ����, operations to determine if the stack is empty
void push(Stack* S, element x);		// ������ top�� ��Ҹ� �߰��ϴ� ����, operations that add elements to top of stack
element pop(Stack* S);				// ���ÿ��� �������� ����� ��� ���� �� ��ȯ�ϴ� ����, operations to delete and return the last stored element on the stack
void clear(Stack* S);				// ���� ����, empty stack

#endif
