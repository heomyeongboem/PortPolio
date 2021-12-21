#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

int testPair(char* exp) {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S = create();
	char symbol, lparen;
	//int i, length = strlen(exp);

	// Fill your code
	//symbol = exp;
	while (*exp) {
		
		
		switch (*exp) {
		case  '(' : push(S, *exp);
			break;
		case  '{':  push(S, *exp);
			break;
		case  '[':  push(S, *exp);
			break;
		case  ')': 
			if(pop(S)!='(')return FALSE;
			break;
		case  '}':  
			if (pop(S) != '{')return FALSE;
			break;
		case  ']': 
			if (pop(S) != '[')return FALSE;
			break;
		}	
		exp++;
	}

	if (!isEmpty(S))return FALSE;

	else
	return TRUE; 
}

int main() {
	int i;
	char* x[4] = { "(A - B) * C) + D", "(A - B) * C + ( D", "A [ B ( C ] )", "{A / (B - C)}" };

	for (i = 0; i < 4; i++) {
		printf("%s ", x[i]);
		if (testPair(x[i]))
			printf("-> ������ ��ȣ�� �ùٸ��� ���Ǿ����ϴ�!\n");
		else
			printf("-> ������ ��ȣ�� Ʋ�Ƚ��ϴ�!\n");
	}

	return 0;
}
