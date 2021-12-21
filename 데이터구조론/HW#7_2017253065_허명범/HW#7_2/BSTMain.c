#include <stdio.h>
#include "BinaryTree.h"
#pragma warning ( disable : 4996 )

void showData(BTData x) {
	printf("%d ", x);
}

void menu() {
	printf("\n*----------------*\n");
	printf("1: ���� Ž�� Ʈ�� ���(������ȸ)\n");	// 1: Binary search tree output (inodertraverse)
	printf("2: ���� Ž�� Ʈ�� ��� ����\n");	// 2: Insert binary search tree node
	printf("3: ���� Ž�� Ʈ�� ��� ����\n");	// 3: Delete binary search tree node
	printf("4: ���� Ž�� Ʈ�� ��� �˻�\n");	// 4: search binary search tree node
	printf("5: ����\n");	// 5: termination
	printf("*----------------*\n");
	printf("�޴� �Է�>> ");	// Enter menu>>
}

int main() {
	BinTree* bt = createBT();
	BinTree* p;
	int choice;
	BTData key;

	setData(bt, 8);
	insertBST(bt, 3);
	insertBST(bt, 10);
	insertBST(bt, 2);
	insertBST(bt, 5);
	insertBST(bt, 14);
	insertBST(bt, 11);
	insertBST(bt, 16);

	while (1) {
		menu();
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("���� Ž�� Ʈ�� ���(���� ��ȸ)\n");	// Binary search tree output (inodertraverse)
			InorderTraverse(bt, showData);
			break;
		case 2:
			printf("������ ���� �Է�: ");	// Enter a number to insert
			scanf("%d", &key);
			insertBST(bt, key);
			printf("���� �� Ʈ�� ���(������ȸ)\n");	// Tree output after insertion (inodertraverse)
			InorderTraverse(bt, showData);
			break;
		case 3:
			printf("������ ���� �Է�: ");	// Enter a number to delete
			scanf("%d", &key);
			deleteBST(bt, key);
			printf("���� �� Ʈ�� ���(������ȸ)\n");	// Tree output after deletion (inodertraverse)
			InorderTraverse(bt, showData);
			break;
		case 4:
			printf("Ž���� ���� �Է�: ");	// Enter a number to search
			scanf("%d", &key);
			p = searchBST(bt, key);
			if (p != NULL) printf("%d�� Ž�� ����", key);	// search successful 
			else printf("%d Ž�� ����", key);	// search failed
			break;
		case 5:
			return 0;
		default:
			printf("�߸� �Է��߽��ϴ�. �޴��� �ٽ� �����ϼ���.\n");	// You entered the wrong input. Please select the Menu again
			break;
		}
	}

	return 0;
}
