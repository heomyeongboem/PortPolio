#pragma once
#ifndef __LINKED_STACK_H__
#define __LINKED_STACK_H__

#include "BinaryTree.h"

#define ERROR NULL
#define TRUE 1
#define FALSE 0

typedef BinTree* element;

// Stack�� ��� ������ ����ü�� ����, define stack's node structure as a structure
typedef struct StackNode {
	element data;
	struct StackNode* link;
}stackNode;

// Stack�� ������ ���(���� �ֱٿ� ���Ե� ���)�� ��Ÿ���� top�� ����ü�� ����, define a top as a structure that represents the last element of stack ( most recently inserted node ) 
typedef struct LinkedStack {
	stackNode* top;
}Stack;

Stack* createStack();				// ���齺�� ����, create a empty stack
int getLength(Stack* S);			// ���ÿ� ����� ��� ������ ��ȯ�ϴ� ����, operations that return the number of elements stored in the stack
int isFull(Stack* S);				// ������ ��ȭ�������� Ȯ���ϴ� ����, operations to determine if the stack is full
int isEmpty(Stack* S);				// ������ ����������� Ȯ���ϴ� ����, operations to determine if the stack is empty
void push(Stack* S, element x);		// ������ top�� ��Ҹ� �߰��ϴ� ����, operations that add elements to top of stack
element pop(Stack* S);				// ���ÿ��� �������� ����� ��� ���� �� ��ȯ�ϴ� ����, operations to delete and return the last stored element on the stack
element peek(Stack* S);				// ���ÿ��� �������� ����� ��Ҹ� ��ȯ�ϴ� ����, operations that return the last stored element in the stack
void displayStack(Stack* S);		// ������ ��� ��� ���, output all elements in the stack 
void clear(Stack* S);				// ���� ����, empth stack

#endif
