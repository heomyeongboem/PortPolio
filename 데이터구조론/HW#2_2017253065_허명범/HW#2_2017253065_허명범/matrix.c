#include <stdio.h>

typedef struct {
	int row;
	int col;
	int value;
}matrix;

void transposeSM(matrix a[], matrix b[]) {
	// Fill you code
	//b는 a의 row column을 뒤바꾼뒤 b는 column을 기준으로 오름차순한다. 
	int i;
	//첫번째 구조체는 행과 열 그리고 0이 아닌 원소의 수를 가르키기 때문에 따로 초기화 시켜준다.
	b[0].col = a[0].row;
	b[0].row = a[0].col;
	b[0].value = a[0].value;


	for (i = 1; i < 11; i++) {//1번째 위치부터 10번째 위치까지 전치연산으로 A->B로 들어간다. 
		b[i].col = a[i].row;
		b[i].row = a[i].col;
		b[i].value = a[i].value;
	}

	for (i = 10; i >= 2; i--) {//B의 1번째 위치부터 10번째 위치까지 오름차순으로 나열된다.
		for (int j = 1; j < i; j++) {//{1,2},{{1,2},{2,3}},.....}조교님 버블 정렬알려주셔서 감사합니다!!!
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
