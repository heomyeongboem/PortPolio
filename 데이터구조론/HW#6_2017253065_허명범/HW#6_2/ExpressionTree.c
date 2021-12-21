#include <stdio.h>
#include <stdlib.h>
#include <string.h>//strlen 함수를 사용하기 위해
#include <ctype.h>//isdigit함수를 사용하기 위해
#include "BinaryTree.h"
#include "LinkedStack.h"

BinTree* createExpTree(char exp[]) {
	Stack* S = createStack();
	BinTree* bNode;
	int expLen = strlen(exp);
	int i;

	// Fill your code
	for (i = 0; i < expLen; i++) {
		bNode = createBT();
		if (isdigit(exp[i])) setData(bNode, exp[i]-'0');

		else {
			setData(bNode, exp[i]);//연산자일시 노드에 값을 넣어주지 않고 먼저 트리를 달려고 하면 인지를 못해서 자식 노드들을 달지 못합니다. 그래서 먼저 작성해줍니다.
			makeRSubtree(bNode, pop(S));
			makeLSubtree(bNode, pop(S));
			
		}
		push(S, bNode);
	}
	return pop(S);
}

int evalExpTree(BinTree* bt) {
	int op1, op2;

	// Fill your code
	if (getLSubtree(bt) == NULL && getRSubtree(bt) == NULL)return getData(bt);
	op1 = evalExpTree(getLSubtree(bt));
	op2 = evalExpTree(getRSubtree(bt));

	//op1 = getData(getLSubtree(bt));
	//op2 = getData(getRSubtree(bt));

	switch (getData(bt))
	{
	case '+':
		return op1 + op2;
	
	case '-':
		return op1 - op2;
	
	case '*':
		return op1 * op2;
	
	case '/':
		return op1 / op2;
	}
	return 0;

}

void showNodeData(int x) {
	if (0 <= x && x <= 9)			// 피연산자 출력, operand output
		printf("%d ", x);
	else						// 연산자 출력, operator output
		printf("%c ", x);
}
//전위 표기법의 수식
void showPrefixExp(BinTree* bt) {

	// Fill your code
	if (bt == NULL)
		return;

	showNodeData(bt->data);		// 연산자 출력, operator output
	showPrefixExp(bt->left);		// 첫 번째 피연산자 출력, first operand output
	showPrefixExp(bt->right);	// 두 번째 피연산자 출력, second operand output
}
//중위표기법의 수식
void showInfixExp(BinTree* bt) {
	if (bt == NULL)
		return;

	if (bt->left != NULL || bt->right != NULL)
		printf(" ( ");

	showInfixExp(bt->left);		// 첫 번째 피연산자 출력, first operand output
	showNodeData(bt->data);		// 연산자 출력, operator output
	showInfixExp(bt->right);	// 두 번째 피연산자 출력, second operand output

	if (bt->left != NULL || bt->right != NULL)
		printf(" ) ");
}
//후위 표기법의 수식
void showPostfixExp(BinTree* bt) {

	// Fill your code
	if (bt == NULL)
		return;

	showPostfixExp(bt->left);		// 첫 번째 피연산자 출력, first operand output
	showPostfixExp(bt->right);	// 두 번째 피연산자 출력, second operand output
	showNodeData(bt->data);		// 연산자 출력, operator output

}
