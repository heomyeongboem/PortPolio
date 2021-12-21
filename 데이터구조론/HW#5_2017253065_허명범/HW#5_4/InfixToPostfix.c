#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"
#include "InfixToPostfix.h"
#include<string.h>

// 연산자, 피연산자, 괄호 -> enueration type 변환, operator, operand, parenthesis -> enueration type transform
precedence getToken(char ch) {
	precedence token;
	switch (ch) {
	case '(':	token = lparen;		break;
	case ')': 	token = rparen;		break;
	case '+':	token = plus;		break;
	case '-':	token = minus;		break;
	case '*':	token = multiply;	break;
	case '/':	token = divide;		break;
	case '%':	token = mod;		break;
	case '\0':	token = eos;		break;
	default:	token = operand;
	}

	return token;
}

// enumeration type에 따라 연산자, 괄호 출력, operator, parenthesis display according to enumeration type
char printToken(precedence token) {
	char ch;
	switch (token) {
	case lparen:	ch = '(';	break;
	case rparen:	ch = ')';	break;
	case plus:		ch = '+';	break;
	case minus:		ch = '-';	break;
	case multiply:	ch = '*';	break;
	case divide:	ch = '/';	break;
	case mod:		ch = '%';	break;
	}

	return ch;
}

// 연산자 우선순위 계산: 괄호 < +, - < *, /, %, calculate operator priority : parentheses < +, - < *, /, %
int prec(precedence symbol) {
	switch (symbol) {
	case lparen:
	case rparen:	return 0;
	case plus:
	case minus:		return 1;
	case multiply:
	case divide:
	case mod:		return 2;
	}
}

// 중위표기식 -> 후위표기식 변환 연산, inflix notation -> postfix notation transform operation
char* toPostfix(Stack* S, char* exp) {
	static char result[256] = "";
	S = create();
	int len = 0, n = 0;
	char symbol = exp[0];
	precedence token = getToken(symbol);		// 연산자의 종류 기록, recording the type of operator

	int data_length = strlen(exp);

	// Fill your code
	
	for (int i = 0; i < data_length+1;i++) {


		symbol = exp[i];
     
		switch (symbol)
		{
		case '+': 
		
				if (isEmpty(S)) {
					push(S, symbol);
					break;
				}

				else if(isEmpty(S)==0)
				{
					while (peek(S)!='(')
					{
						result[len] = pop(S);
						/*
						if (peek(S) == '(') {
							push(S, symbol);
							break;
						}
						else {
							result[len] = pop(S);
							len++;
						}
						*/
					}
				}

		case '*':

			if (peek(S) == '*')
			{
			result[len] = pop(S);
			push(S, symbol);
			len++;
			break;
			}
			else if(peek(S)!='*')
			{
			push(S, symbol);
			break;
			}
			


		case '(':
			push(S, symbol);
			break;

		case ')':
			do {
			if (peek(S) == '(') {
					pop(S);
				}
				else if(peek(S)!= '('){
					result[len] = pop(S);
					len++;
				}
			} while (peek(S) != '(');
			pop(S);
			
		default:
			
			if (symbol != ')'){//얘내는 이렇게 조건문을 넣어주지 않으면 ( )가 출력문에 들어가는 불상사가 생긴다. 
				if (symbol != '(') {
				result[len] = symbol;
			len++;
				}
			}
			
			
			break;
		}	
	}

	len--;
	while (!isEmpty(S)) {

		if (peek(S) == '(')pop(S);

		else if (peek(S)!= '(') {
		result[len]=pop(S);
        len++;
		}	
	}
	return result;
}


// 후위표기식의 계산 연산, computation of postfix notaion
float evalPostfix(Stack* S, char* exp) {
	
	//뻘짓한거
	
	/*
	int op1, op2;
	int n = 0;
	char s[3];
	char k;
	
	
	char symbol = exp[0];
	char x, y,ten,one;
	int value;
	//precedence token = getToken(symbol);
	S = create();

	// Fill your code	
	int data_length = strlen(exp);
	for (int i = 0; i < data_length; i++) {


		symbol = exp[i];

		switch (symbol)
		{
		case '+':

			 x = pop(S);
			 y = pop(S);
			op1 = atoi(&x);
			op2 = atoi(&y);
			n = op1 + op2;
			
			sprintf(&s, "%d", n);
	
			push(S, s[0]);
			if (s[1] != 0) {
			push(S, s[1]);
			break;
			}
			break;


		case '*':
			
			 x = pop(S);
			 y = pop(S);
			op1 = atoi(&x);
			op2 = atoi(&y);
			
 			n = op1 * op2;

			sprintf(&s,"%d", n);
			push(S, s[0]);

			
			if (s[1] != 0) {
				push(S, s[1]);
				break;
			}
			
			break;
		
		default:

			push(S, symbol);
			break;
		}
	}
	
	one = pop(S);
	ten = pop(S);

	op1 = atoi(&ten);
	op2 = atoi(&one);

	value = 10 * op1 + op2;
	
	return value;
	*/

	

	int op1, op2;
	int n = 0;
	//char s[3];
	//char k;


	char symbol = exp[0];
	char x, y, ten, one;
	int value;
	char integer;
	//precedence token = getToken(symbol);
	S = create();

	// Fill your code	
	int data_length = strlen(exp);
	for (int i = 0; i < data_length; i++) {


		symbol = exp[i];

		switch (symbol)
		{
		case '+':
			op1 = pop(S);//위 두 연산들은 스택에 있는 두개의 정수들을 pop으로 받아와 연산시켜주고 다시 넣어준다.
			op2 = pop(S);
			n = op1 + op2;
			push(S, n);			
			break;


		case '*':		
			op1 = pop(S);
			op2 = pop(S);
			n = op1 * op2;
			push(S, n);
			break;

		default:
			integer = atoi(&symbol);//스택에 값을 넣을 때 상수 값으로 넣는 것이 아닌 정수로 값을 넣어준다.(연산시:정수, 입력시:정수) 이걸 상수로 받으면 골치 아파진다.(연산시:상수->정수, 입력시:정수->상수)
			push(S, integer);
			break;
		}
	}

	

	

	return pop(S);

}
