#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

// ���� ���� Ʈ�� ���� ����, blank binary tree generation operations
BinTree* createBT() {
	BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
	bt->data = EMPTY;
	bt->left = NULL;
	bt->right = NULL;
	return bt;
}

// ���� Ʈ���� ����ִ��� �˻��ϴ� ����, operations to check if the binary tree is empty
int isBTEmpty(BinTree* bt) {
	if (bt->left == NULL && bt->right == NULL && bt->data == EMPTY)
		return TRUE;
	else
		return FALSE;
}

// ���� ����Ʈ���� bt1, ������ ����Ʈ���� bt2, x���� ������ ��带 ��Ʈ�� �ϴ� ����Ʈ�� ��ȯ, returns a binary tree rooted at a node whose left subtree is bt1, whose right subtree is bt2, x
BinTree* makeBT(BinTree* bt1, BTData x, BinTree* bt2) {
	BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
	bt->data = x;
	bt->left = bt1;
	bt->right = bt2;
	return bt;
}

// bt2�� bt1�� ���� ����Ʈ���� ����, connect bt2 to the left subtree of bt1
void makeLSubtree(BinTree* bt1, BinTree* bt2) {

	// Fill your code
	bt1->left = bt2;


}

// bt2�� bt1�� ������ ����Ʈ���� ����, connect bt2 to the right subtree of bt1
void makeRSubtree(BinTree* bt1, BinTree* bt2) {

	// Fill your code
	bt1->right = bt2;


}

// bt�� ���� ����Ʈ���� ��ȯ, returns the left subtree of bt
BinTree* getLSubtree(BinTree* bt) {

	// Fill your code
	if (bt->left == NULL)return NULL;
	else return bt->left;


}

// bt�� ������ ����Ʈ���� ��ȯ, returns the right subtree of bt
BinTree* getRSubtree(BinTree* bt) {

	// Fill your code
	if (bt->right == NULL)return NULL;
	else return bt->right;


}

// bt�� root ��忡 x �� ����, store x value in root node of bt
void setData(BinTree* bt, BTData x) {

	// Fill your code
	bt->data = x;
	bt->left = NULL;
	bt->right = NULL;
}

// bt�� root�� ����� �����͸� ��ȯ, ���� ������ -1 ��ȯ, retruns data stored in bt's root, returns -1 if no value exists
BTData getData(BinTree* bt) {

	// Fill your code
	if (bt==NULL)return -1;
	else return bt->data;
}

// bt�� ����Ű�� ��带 ��Ʈ�� �ϴ� Ʈ�� ���� �Ҹ�, destroy all trees rooted at nodes bt points to
void deleteBT(BinTree* bt) {
	if (bt == NULL)
		return;

	deleteBT(bt->left);
	deleteBT(bt->right);

	printf("tree �� ����: %d \n", bt->data);	// delete tree data: %d 
	free(bt);
}

// ���� ��ȸ , inorder
void InorderTraverse(BinTree* bt, visitFuncPtr action) {

	// Fill your code
	if (bt != NULL)//��尡 ������ 
	{
		InorderTraverse(bt->left, action);
		action(bt->data);
		InorderTraverse(bt->right, action);
	}

}

// ���� ��ȸ, preorder
void PreorderTraverse(BinTree* bt, visitFuncPtr action) {

	// Fill your code
	if (bt != NULL)
	{
		action(bt->data);
		PreorderTraverse(bt->left, action);
		PreorderTraverse(bt->right, action);
	}
}

// ���� ��ȸ, postorder
void PostorderTraverse(BinTree* bt, visitFuncPtr action) {

	// Fill your code
	if (bt != NULL)
	{
		PostorderTraverse(bt->left, action);
		PostorderTraverse(bt->right, action);
		action(bt->data);
	}
}

