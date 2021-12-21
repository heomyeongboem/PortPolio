#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

// 공백 이진 트리 생성 연산, empty binary tree generation operations
BinTree* createBT() {
	BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
	bt->key = EMPTY;
	bt->left = NULL;
	bt->right = NULL;
	return bt;
}

// 이진 트리가 비어있는지 검사하는 연산, operations to check if the binary tree is empty
int isBTEmpty(BinTree* bt) {
	if (bt->left == NULL && bt->right == NULL && bt->key == EMPTY)
		return TRUE;
	else
		return FALSE;
}

// 왼쪽 서브트리가 bt1, 오른쪽 서브트리가 bt2, x값을 가지는 노드를 루트로 하는 이진트리 반환, returns a binary tree rooted at a node whose left subtree is bt1, whose right subtree is bt2, x
BinTree* makeBT(BinTree* bt1, BTData x, BinTree* bt2) {
	BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
	bt->key = x;
	bt->left = bt1;
	bt->right = bt2;
	return bt;
}

// bt2를 bt1의 왼쪽 서브트리로 연결, connect bt2 to the left subtree of bt1
void makeLSubtree(BinTree* bt1, BinTree* bt2) {

	// Fill your code
	bt1->left = bt2;

}

// bt2를 bt1의 오른쪽 서브트리로 연결, connect bt2 to the right subtree of bt1
void makeRSubtree(BinTree* bt1, BinTree* bt2) {

	// Fill your code
	bt1->right = bt2;

}

// bt의 왼쪽 서브트리를 반환, returns the left subtree of bt
BinTree* getLSubtree(BinTree* bt) {

	// Fill your code
	if (bt->left == NULL)return NULL;
	else return bt->left;

}

// bt의 오른쪽 서브트리를 반환, returns the right subtree of bt
BinTree* getRSubtree(BinTree* bt) {

	// Fill your code
	if (bt->right == NULL)return NULL;
	else return bt->right;

}

// bt의 root 노드에 x 값 저장, store x value in root node of bt
void setData(BinTree* bt, BTData x) {

	// Fill your code
	bt->key = x;
	bt->left = NULL;
	bt->right = NULL;
}

// bt의 root에 저장된 데이터를 반환, returns data stored in bt's root
BTData getData(BinTree* bt) {

	// Fill your code
	if (bt == NULL)return -1;
	else return bt->key;

}

// bt가 가리키는 노드를 루트로 하는 트리 전부 소멸, destroy all trees rooted at nodes bt points to
void deleteBT(BinTree* bt) {
	if (bt == NULL)
		return;

	deleteBT(bt->left);
	deleteBT(bt->right);

	printf("delete tree data: %d \n", bt->key);
	free(bt);
}

// 중위 순회, inorder traversal
void InorderTraverse(BinTree* bt, visitFuncPtr action) {

	// Fill your code
	if (bt != NULL) {
		InorderTraverse(bt->left, action);
		action(bt->key);
		InorderTraverse(bt->right, action);
	}
}

// 데이터 x가 저장된 노드 탐색, searching nodes where data x is stored
BinTree* searchBST(BinTree* bt, BTData x) {
	BinTree* p = bt;

	// Fill your code
	if (p == NULL) { //
		//printf("ERROR:찾는 키가 없습니다.\n");
		return NULL; 
	}
	if (x == p->key)return p;//x 값과 루트 노드의 값이 같으면 찾았다 하면서 그 위치 반환
	if (x < p->key)return searchBST(p->left, x);//x값이 루트 노드의 값보다 작으면 왼쪽 서브 트리로 이동해야되기 때문에 재귀 함수에다가 왼쪽 서브 트리를 넣어주면서 재귀를 함
	else return searchBST(p->right, x);//얘는 반대로 x 값이 루트 노드의 값보다 크면 오른쪽 서브 트리로 이동해야되기 때문에 재귀함수에다가 오른쪽 서브 트리를 넣어 재귀를 시작함

}

// 데이터 x 저장, insert data x
void insertBST(BinTree* bt, BTData x) {
	BinTree* p = bt;
	BinTree* parent = NULL;

	// 삽입할 노드 탐색, searching nodes to insert
	// Fill your code
	//searchBST(p, x);
	
	while (p != NULL) {
		if (x == p->key) {
			printf("ERROR:이미 같은 키가 있습니다.\n");
			return 0;
		}
		parent = p;
		if (x < p->key)p = p->left;
		else p = p->right;
	}

		// 삽입할 노드 생성, create node to insert
		// Fill your code
		
	BinTree * newNode = (BinTree*)malloc(sizeof(BinTree));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
	// 삽입 노드 연결, connect insert node
	// Fill your code
	
		if (bt == NULL)bt = newNode;
		if (x < parent->key)parent->left = newNode;
		else parent->right = newNode;
}

// 데이터 x 노드 삭제, delete data x node
void deleteBST(BinTree* bt, BTData x) {

	// Fill your code
	
	BinTree* p=searchBST(bt, x);//p의 위치 찾기
	 
	BinTree* parent=NULL;

	BinTree* k = bt;
	while (k != NULL) {

		
		if (k->left!=NULL&&k->left->key==x) { 
			parent = k;
			break;
		}
		
		
		else  if (k->right != NULL && k->right->key==x) {
			parent = k;
			break;
		}
		else {
			parent = k;
			if (x < k->key)k = k->left;
			else k = k->right;
		}
	}

	// 삭제할 노드가 없는 경우, if there are no nodes to delete
	// Fill your code
	if (p == NULL)return 0;

	// CASE 1: 삭제할 노드의 차수가 0인 경우, CASE 1: if the node to be deleted has a degree of 0
	// Fill your code
	if (p->left == NULL && p->right == NULL) {
		if (parent->left == p)parent->left = NULL;
		else parent->right = NULL;
	}

	// CASE 2: 삭제할 노드의 차수가 1인 경우, CASE 2: if the node to be deleted has a degree of 1
	// Fill your code
	else if (p->left == NULL || p->right == NULL) {
	if(p->left!=NULL){
		if (parent->left == p)parent->left = p->left;
		else parent->right = p->left;
	}
	else {
		if (parent->left == p)parent->left = p->right;
		else parent->right = p->right;
	}
	}

	// CASE 3: 삭제할 노드의 차수가 2인 경우, CASE 3: if the node to be deleted has a degree of 2
	// Fill your code
	else if (p->left != NULL && p->right != NULL) {
		BinTree* q = p->left;


		//우리는 왼쪽 서브트리에서 제일 큰 값을 찾기로 결정했으므로 왼쪽 서브트리에서 제일 오른쪽 노드를 찾는다.
		while (1) {
			if (q->right == NULL)break;
			else { 
				q = q->right;
			}
		}

		//parent->right = q;
		//q->right = p->right;
		BTData u= q->key;//후계자노드의 key 값만 변수 u에 넣어준다. 왜냐하면 후계자 노드를 삭제 한다음 후계자 노드의 key값을 삭제하려고 했던 노드의 key값에 넣어주고 삭제하려했던 노드는 원래 그 자리에 있게 만들어주므로써
		//여러가지 예외처리를 방지 할 수 있기 때문이다. 이게 제일 어려웠습니다.
		deleteBST(bt, q->key);
		p->key = u;
	}

}
