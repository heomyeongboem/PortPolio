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
	 
	// newnode 생성
	Node* newnode = malloc(sizeof(Node));
	newnode->coef = coef;
	newnode->exp = exp;
	newnode->link = NULL;

	//공백 리스트 인 경우
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
	     //계수 A==B
		if (polyA->exp == polyB->exp) {
			sub= (polyA->coef) - (polyB->coef);
			if(sub!=0)appendTerm(C, sub, polyA->exp);
			
			polyA = polyA->link;
			polyB = polyB->link;
			if (polyA == NULL || polyB == NULL)break;//이렇게 각각의 if 문안에 break문을 쓴 이유는 만일 while문이 돌기전인 첫번째 상황이 끝나면서 A가 NULL이 되는 상황이 온다면 else if(polyA->exp > polyB->exp)
		}//문에서 A->exp=NULL인 상황이기 때문에 중지가 걸리고 맙니다. 그래서 while문이 돌기전에 NULL이 오는 상황을 막고자 했습니다. 
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
	//while문을 빠져나왔다는 것은 polyA 나 polyB 둘 중 하나가 NULL이 되었기 때문
	//polyB가 NULL인 경우
	if (polyA != NULL) {
		while (polyA != NULL) {
			appendTerm(C, polyA->coef, polyA->exp);
			polyA = polyA->link;
		}	
	}
	//polyB가 NULL인 경우
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
