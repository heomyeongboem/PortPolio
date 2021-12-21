#include <stdio.h>
#include <stdlib.h>
#include <string.h>//strlen �Լ��� ����ϱ� ����
#include <ctype.h>//isdigit�Լ��� ����ϱ� ����
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
			setData(bNode, exp[i]);//�������Ͻ� ��忡 ���� �־����� �ʰ� ���� Ʈ���� �޷��� �ϸ� ������ ���ؼ� �ڽ� ������ ���� ���մϴ�. �׷��� ���� �ۼ����ݴϴ�.
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
	if (0 <= x && x <= 9)			// �ǿ����� ���, operand output
		printf("%d ", x);
	else						// ������ ���, operator output
		printf("%c ", x);
}
//���� ǥ����� ����
void showPrefixExp(BinTree* bt) {

	// Fill your code
	if (bt == NULL)
		return;

	showNodeData(bt->data);		// ������ ���, operator output
	showPrefixExp(bt->left);		// ù ��° �ǿ����� ���, first operand output
	showPrefixExp(bt->right);	// �� ��° �ǿ����� ���, second operand output
}
//����ǥ����� ����
void showInfixExp(BinTree* bt) {
	if (bt == NULL)
		return;

	if (bt->left != NULL || bt->right != NULL)
		printf(" ( ");

	showInfixExp(bt->left);		// ù ��° �ǿ����� ���, first operand output
	showNodeData(bt->data);		// ������ ���, operator output
	showInfixExp(bt->right);	// �� ��° �ǿ����� ���, second operand output

	if (bt->left != NULL || bt->right != NULL)
		printf(" ) ");
}
//���� ǥ����� ����
void showPostfixExp(BinTree* bt) {

	// Fill your code
	if (bt == NULL)
		return;

	showPostfixExp(bt->left);		// ù ��° �ǿ����� ���, first operand output
	showPostfixExp(bt->right);	// �� ��° �ǿ����� ���, second operand output
	showNodeData(bt->data);		// ������ ���, operator output

}
