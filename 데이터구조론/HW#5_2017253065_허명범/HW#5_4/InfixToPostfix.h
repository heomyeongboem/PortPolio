#ifndef __INFIX_TO_POSTFIX_H__
#define __INFIX_TO_POSTFIX_H__

// ������, �ǿ�����, ��ȣ�� ó���ϱ� ���� enumeration type ����, define of the enumeration type to handle operators, operands, and parentheses
typedef enum {
	lparen, rparen, plus, minus, multiply, divide, mod, eos, operand
}precedence;

precedence getToken(char ch);			// ������, �ǿ�����, ��ȣ -> enueration type ��ȯ, operator, operand, parenthesis -> enueration type transform
char printToken(precedence token);		// enumeration type�� ���� ������, ��ȣ ���, operator, parenthesis display according to enumeration type
int prec(precedence symbol);			// ������ �켱���� ���: ��ȣ < +, - < *, /, %, calculate operator priority : parentheses < +, - < *, /, %
char* toPostfix(Stack* S, char* exp);	// ����ǥ��� -> ����ǥ��� ��ȯ ����, inflix notation -> postfix notation transform operation
float evalPostfix(Stack* S, char* exp);	// ����ǥ����� ��� ����, computation of postfix notaion

#endif
#pragma once
