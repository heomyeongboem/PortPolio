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
		
		printf("학번을 입력하시오:");
		scanf_s("%d", &s[i].stdNum); 

		printf("이름을 입력하시오:");
		scanf_s("%s", s[i].name, sizeof(s->name)); //scanf_s 가 문자열을 받을때에는 방식이 옛날과는 달라진 것 같습니다.

		printf("들어온시간을 입력하시오:");
		scanf_s("%d", &s[i].inTime);

		people temp;
		int i;
		int j;
		for (i = N - 1; i >= 1; i--) {//구조체 배열 값이 2개가 들어왔을 때 부터 시작
			for (j = 0; j < i; j++) {
				if (s[j].inTime>s[j+1].inTime) { //앞에 있는 구조체에 대한 시간값이 뒤에 있는 구조체에 대한 시간의 값보다 더 크면 
					temp = s[j];  //앞에 있는 구조체 값을 temp로 옮겨주고
					s[j] = s[j + 1]; //뒤에 있는 구조체 값을 앞에 구조체로 옮겨준다
					s[j + 1] = temp; //마지막으로 앞에 구조체에서 받아왔던 temp에 있는 값을 뒤에 있는 값으로 옮겨준다.
				}

			}

		}
	}

	if (N == 5) { //만일 5개를 입력받게 된다면
		for (int d = 0; d < 5; d++) {
			printf("%d %s %d\n", (s + d)->stdNum, (s + d)->name, (s + d)->inTime); //5개를 반복문을 이용하여 배열에 저장되어 있는 값들을 출력해준다.
		}
	}
}

