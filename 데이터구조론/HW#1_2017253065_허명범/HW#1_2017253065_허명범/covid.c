#define _CTR_SECURE_NO_WARNING
#include <stdio.h>

typedef struct _people 
{
	int stdNum;
	char name[7];
	int inTime;
}people;

int main(void) {
	int N = 0;
	int number = 1;
	people s[5];
	for (int i = 0; i < 5;i++) {
		N++;
		
		printf("�й��� �Է��Ͻÿ�:");
		scanf_s("%d", &s[i].stdNum); 

		printf("�̸��� �Է��Ͻÿ�:");
		scanf_s("%s", s[i].name, sizeof(s->name)); //scanf_s �� ���ڿ��� ���������� ����� �������� �޶��� �� �����ϴ�.

		printf("���½ð��� �Է��Ͻÿ�:");
		scanf_s("%d", &s[i].inTime);

		people temp;
		int i;
		int j;
		for (i = N - 1; i >= 1; i--) {//����ü �迭 ���� 2���� ������ �� ���� ����
			for (j = 0; j < i; j++) {
				if (s[j].inTime>s[j+1].inTime) { //�տ� �ִ� ����ü�� ���� �ð����� �ڿ� �ִ� ����ü�� ���� �ð��� ������ �� ũ�� 
					temp = s[j];  //�տ� �ִ� ����ü ���� temp�� �Ű��ְ�
					s[j] = s[j + 1]; //�ڿ� �ִ� ����ü ���� �տ� ����ü�� �Ű��ش�
					s[j + 1] = temp; //���������� �տ� ����ü���� �޾ƿԴ� temp�� �ִ� ���� �ڿ� �ִ� ������ �Ű��ش�.
				}

			}

		}
	}

	if (N == 5) { //���� 5���� �Է¹ް� �ȴٸ�
		for (int d = 0; d < 5; d++) {
			printf("%d %s %d\n", (s + d)->stdNum, (s + d)->name, (s + d)->inTime); //5���� �ݺ����� �̿��Ͽ� �迭�� ����Ǿ� �ִ� ������ ������ش�.
		}
	}
}

