#include <stdio.h>

typedef struct {
	int row;
	int col;
	int value;
}matrix;

void transposeSM(matrix a[], matrix b[]) {
	// Fill you code
	//b�� a�� row column�� �ڹٲ۵� b�� column�� �������� ���������Ѵ�. 
	int i;
	//ù��° ����ü�� ��� �� �׸��� 0�� �ƴ� ������ ���� ����Ű�� ������ ���� �ʱ�ȭ �����ش�.
	b[0].col = a[0].row;
	b[0].row = a[0].col;
	b[0].value = a[0].value;


	for (i = 1; i < 11; i++) {//1��° ��ġ���� 10��° ��ġ���� ��ġ�������� A->B�� ����. 
		b[i].col = a[i].row;
		b[i].row = a[i].col;
		b[i].value = a[i].value;
	}

	for (i = 10; i >= 2; i--) {//B�� 1��° ��ġ���� 10��° ��ġ���� ������������ �����ȴ�.
		for (int j = 1; j < i; j++) {//{1,2},{{1,2},{2,3}},.....}������ ���� ���ľ˷��ּż� �����մϴ�!!!
			if (b[j].row > b[j + 1].row) {
				int rowtemp = b[j].row;
				int coltemp = b[j].col;
				int valuetemp = b[j].value;

				b[j].row = b[j + 1].row;
				b[j].col = b[j + 1].col;
				b[j].value = b[j + 1].value;

				b[j + 1].row = rowtemp;
				b[j + 1].col = coltemp;
				b[j + 1].value = valuetemp;
			}

		}

	}

}

int main() {
	int i, j;
	matrix a[11] = { {8,7,10},
						{0,2,2},
						{0,6,12},
						{1,4,7},
						{2,0,23},
						{3,3,31},
						{4,1,14},
						{4,5,25},
						{5,6,6},
						{6,0,52},
						{7,4,11}
	};
	matrix b[11] = { 0, };
	transposeSM(a, b);

	printf("Matrix a\n");
	for (i = 0; i < 11; i++)
		printf("%d: %d %d %d\n", i, a[i].row, a[i].col, a[i].value);
	printf("Transpose Matrix b\n");
	for (i = 0; i < 11; i++)
		printf("%d: %d %d %d\n", i, b[i].row, b[i].col, b[i].value);
	return 0;
}
