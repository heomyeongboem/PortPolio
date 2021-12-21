#include <stdio.h>
#include "ExpressionTree.h"

int main() {
	char exp[] = "12+7*";
	BinTree* bt = createExpTree(exp);

	printf("\n���� ǥ����� ����: ");	// Formula for prefix notation:
	showPrefixExp(bt);
	printf("\n\n");

	printf("���� ǥ����� ����: ");	// Formula for infix notation:
	showInfixExp(bt);
	printf("\n\n");

	printf("���� ǥ����� ����: ");	// Formula for postfix notation
	showPostfixExp(bt);
	printf("\n\n");
	
	printf("���� ���: %d \n", evalExpTree(bt));	// Computational Results:

	return 0;
}