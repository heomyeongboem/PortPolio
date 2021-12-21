#ifndef __POLY_LINKED_LIST_H__
#define __POLY_LINKED_LIST_H__

typedef struct PolyNode {
	float coef;
	int exp;
	struct PolyNode* link;
}Node;

typedef struct PolyList {
	Node* head;
	Node* last;
}polyList;

polyList* initList();									// ���鸮��Ʈ ����, generate a blank list 
void appendTerm(polyList* PL, float coef, int exp);		// ���׽� ����Ʈ ������ ���� �� �߰�, Add terms as the last node in the polynomial list
polyList* subPoly(polyList* A, polyList* B);			// �� ���׽��� �E�� subtraction polyA, polyB
void displayPoly(polyList* PL);							// ���׽� ����Ʈ�� ��� ��� ���, display all elements in a polynomial list

#endif
