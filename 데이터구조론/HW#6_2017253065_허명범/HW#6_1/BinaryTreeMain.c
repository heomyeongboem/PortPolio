#include <stdio.h>
#include "BinaryTree.h"

void showData(BTData x) {
	printf("%d ", x);
}

int main() {
	BinTree* root = createBT();
	BinTree* bt1 = createBT();
	BinTree* bt2 = createBT();
	BinTree* bt3 = createBT();
	BinTree* bt4 = createBT();
	BinTree* bt5 = createBT();


	setData(root, 1);
	setData(bt1, 2);
	setData(bt2, 3);
	setData(bt3, 4);
	setData(bt4, 5);
	setData(bt5, 6);

	makeLSubtree(root, bt1);	//				root
	makeRSubtree(root, bt2);	//		bt1					bt2
	makeLSubtree(bt1, bt3);		//	bt3		bt4			bt5
	makeRSubtree(bt1, bt4);
	makeLSubtree(bt2, bt5);

	// #1 root, ���� �ڽ� ��� �� ���, #1 output root, left child node, etc
	printf("\n=== (1) ��� ===\n");	// === (1) Print ===
	printf("root: %d\n", getData(root));	// root
	printf("root�� ���� �ڽ�: %d\n", getData(getLSubtree(root)));	// left child of root: %d
	printf("root�� ������ �ڽ�: %d\n", getData(getRSubtree(root)));	// right child of root: %d
	printf("root�� ���� �ڽ��� ���� �ڽ�: %d\n", getData(getLSubtree(getLSubtree(root))));	// left child of left child of root: %d
	printf("root�� ���� �ڽ��� ������ �ڽ�: %d\n", getData(getRSubtree(getLSubtree(root))));	// right child of left child of root: %d
	printf("root�� ������ �ڽ��� ���� �ڽ�: %d\n", getData(getLSubtree(getRSubtree(root))));	// left child of right child of root: %d
	printf("root�� ������ �ڽ��� ������ �ڽ�: %d\n", getData(getRSubtree(getRSubtree(root))));	// right child of right child of root: %d

	
	// #2 ���� ��ȸ, #2 InorderTraverse
	printf("\n=== (2) ���� ��ȸ ===\n");	// === (2) Inorder Traverse ===
	InorderTraverse(root, showData);
	printf("\n");
	
	// #3 PreorderTraverse
	printf("\n=== (3) ���� ��ȸ ===\n");	// === (3) Preorder Traverse ===
	PreorderTraverse(root, showData);
	printf("\n");

	// #4 PostorderTraverse
	printf("\n=== (4) ���� ��ȸ ===\n");	// === (4) Postorder Traverse ===
	PostorderTraverse(root, showData);
	printf("\n");

	// #5 deleteTree
	printf("\n=== (5) tree �Ҹ� ===\n");	// === (5) Delete Tree ===	
	deleteBT(root);
	printf("\n");
	
	return 0;
}
