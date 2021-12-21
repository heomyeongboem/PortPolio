#pragma once
#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#define TRUE 1
#define FALSE 0
#define EMPTY 123456789

typedef int BTData;

typedef struct BinaryTreeNode {
	BTData key;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BinTree;

BinTree* createBT();			// ���� ���� Ʈ�� ���� ����, empty binary tree generation operations
int isBTEmpty(BinTree* bt);		// ���� Ʈ���� ����ִ��� �˻��ϴ� ����, operations to check if the binary tree is empty
BinTree* makeBT(BinTree* bt1, BTData x, BinTree* bt2); 	// ���� ����Ʈ���� bt1, ������ ����Ʈ���� bt2, x���� ������ ��带 ��Ʈ�� �ϴ� ����Ʈ�� ��ȯ, returns a binary tree rooted at a node whose left subtree is bt1, whose right subtree is bt2, x
void makeLSubtree(BinTree* bt1, BinTree* bt2);		// bt2�� bt1�� ���� ����Ʈ���� ����, connect bt2 to the left subtree of bt1
void makeRSubtree(BinTree* bt1, BinTree* bt2);		// bt2�� bt1�� ������ ����Ʈ���� ����, connect bt2 to the right subtree of bt1
BinTree* getLSubtree(BinTree* bt);		// bt�� ���� ����Ʈ���� ��ȯ, returns the left subtree of bt
BinTree* getRSubtree(BinTree* bt);		// bt�� ������ ����Ʈ���� ��ȯ, returns the right subtree of bt
void setData(BinTree* bt, BTData x);	// bt�� root ��忡 x �� ����, store x value in root node of bt
BTData getData(BinTree* bt);			// bt�� root�� ����� �����͸� ��ȯ, returns data stored in bt's root
void deleteBT(BinTree* bt);	// bt�� ����Ű�� ��带 ��Ʈ�� �ϴ� Ʈ�� ���� �Ҹ�, destroy all trees rooted at nodes bt points to

typedef void visitFuncPtr(BTData x);						// ��� �湮�� action ����, define action on node visit
void InorderTraverse(BinTree* bt, visitFuncPtr action);		// ���� ��ȸ, inorder traversal

BinTree* searchBST(BinTree* bt, BTData x);	// ������ x�� ����� ��� Ž��, searching nodes where data x is stored
void insertBST(BinTree* bt, BTData x);		// ������ x ����, insert data x
void deleteBST(BinTree* bt, BTData x);	// ������ x ��� ����, delete data x node

#endif

