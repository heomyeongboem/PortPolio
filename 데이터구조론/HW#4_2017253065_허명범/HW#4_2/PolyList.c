#include <stdio.h>
#include <stdlib.h>
#include "PolyList.h"

polyList* initList() {
	polyList* PL = (polyList*)malloc(sizeof(polyList));
	PL->head = NULL;
	PL->last = NULL;
	return PL;
}

void appendTerm(polyList* PL, float coef, int exp) {

	// Fill your code
	 
	// newnode ����
	Node* newnode = malloc(sizeof(Node));
	newnode->coef = coef;
	newnode->exp = exp;
	newnode->link = NULL;

	//���� ����Ʈ �� ���
	if (PL->head == NULL)
	{
		PL->head = newnode;
	}
	else 
	{
		PL->last->link = newnode;
	}
	PL->last = newnode;
}

polyList* subPoly(polyList* A, polyList* B) {
	polyList* C = initList();
	Node* polyA = A->head;
	Node* polyB = B->head;
	int sub = 0;

	// Fill your code
	while (polyA != NULL || polyB != NULL)
	{
	     //��� A==B
		if (polyA->exp == polyB->exp) {
			sub= (polyA->coef) - (polyB->coef);
			if(sub!=0)appendTerm(C, sub, polyA->exp);
			
			polyA = polyA->link;
			polyB = polyB->link;
			if (polyA == NULL || polyB == NULL)break;//�̷��� ������ if ���ȿ� break���� �� ������ ���� while���� �������� ù��° ��Ȳ�� �����鼭 A�� NULL�� �Ǵ� ��Ȳ�� �´ٸ� else if(polyA->exp > polyB->exp)
		}//������ A->exp=NULL�� ��Ȳ�̱� ������ ������ �ɸ��� ���ϴ�. �׷��� while���� �������� NULL�� ���� ��Ȳ�� ������ �߽��ϴ�. 
		//A>B
		else if (polyA->exp > polyB->exp)
		{
			appendTerm(C, polyA->coef, polyA->exp);
			polyA = polyA->link;
			if (polyA == NULL || polyB == NULL)break;
		}
		//A<B
		else if(polyA->exp < polyB->exp) {
			float s = -(polyB->coef);
			appendTerm(C, s, polyB->exp);
			polyB = polyB->link;
			if (polyA == NULL || polyB == NULL)break;
		}

	}
	//while���� �������Դٴ� ���� polyA �� polyB �� �� �ϳ��� NULL�� �Ǿ��� ����
	//polyB�� NULL�� ���
	if (polyA != NULL) {
		while (polyA != NULL) {
			appendTerm(C, polyA->coef, polyA->exp);
			polyA = polyA->link;
		}	
	}
	//polyB�� NULL�� ���
	else if (polyB != NULL) {
		while (polyB != NULL) {
			appendTerm(C, polyB->coef, polyB->exp);
			polyB = polyB->link;
		}
	}


	return C;
}

void displayPoly(polyList* PL) {
	Node* p = PL->head;
	for (; p; p = p->link) {
		if (p->coef > 0)
			printf("\t+");
		else
			printf("\t");
		printf("%.0fx^%d", p->coef, p->exp);
	}
	printf("\n");
}
