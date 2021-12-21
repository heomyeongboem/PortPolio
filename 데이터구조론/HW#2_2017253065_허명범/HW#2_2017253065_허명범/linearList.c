
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

#define MAX_SIZE 100		// 배열의 최대 크기

typedef int element;
typedef struct {
	element list[MAX_SIZE];	// 배열 정의
	int length;		// 현재 배열에 저장된 자료들의 개수
}ArrayListType;

// 오류 처리 함수
void error(char* message)
{
	printf("%s\n", message);
}

// 리스트 초기화
void init(ArrayListType* L)
{
	L->length = 0;

}

// 빈 리스트 검사
// 리스트가 비어 있으면 1을 반환
// 그렇지 않으면 0을 반환
int isEmpty(ArrayListType* L)
{
	if (L->length == 0) {
		printf("IS EMPTY\n");
		return 1;
	}
	else return 0;
}

// 리스트가 포화상태인 검사
// 리스트가 가득차 있으면 1을 반환
// 그렇지 않으면 0을 반환
int isFull(ArrayListType* L)
{
	return L->length == MAX_SIZE;
}

// 리스트의 모든 요소 출력
void display(ArrayListType* L)
{
	int i;
	printf("===Print Lists===\n");
	for (i = 0; i < L->length; i++)
		printf("ArrayList[%d]: %d\n", i, L->list[i]);
}

// 삽입 함수 
// pos: 삽입하고자 하는 위치
// item: 삽입하고자 하는 자료
void insert(ArrayListType* L, int pos, element item)
{
	// Fill your code
	int i;
	if (isFull(L))
		error((char*)"List is Full!");
	else if (pos < 0 || (pos > L->length))
		error((char*)"Index Error");
	else {
		for (i = (L->length - 1); i >= pos; i--)
			L->list[i + 1] = L->list[i];

		L->list[pos] = item;
		printf("ArrayList[%d]에 %d 삽입\n", pos, item);
		L->length++;
	}
}

// 리스트 맨 앞에 요소 삽입
void insertFirst(ArrayListType* L, element item)
{
	// Fill your code
	int i;
	if (isFull(L))
		error((char*)"List is Full!");

	else {
		for (i = (L->length - 1); i >= 0; i--)//맨 뒤 인덱스부터 맨 앞 인덱스인 0까지 뒤로 밀어준다.
			L->list[i + 1] = L->list[i];

		L->list[0] = item;
		printf("ArrayList[0]에 %d 삽입\n", item);
		L->length++;
	}
}

// 리스트 맨 끝에 요소 삽입
void insertLast(ArrayListType* L, element item)
{
	// Fill your code

	if (isFull(L))
		error((char*)"List is Full!");

	else {
		L->list[L->length] = item;
		printf("ArrayList[%d]에 %d 삽입\n", L->length, item);
		L->length++;
	}
}

// 삭제 함수
// pos: 삭제하고자 하는 위치
// 반환값: 삭제되는 자료
element delete(ArrayListType* L, int pos)
{
	// Fill your code
	int i;
	element item;
	if (isEmpty(L))//비어있는지
		error((char*)"List is Empty");
	else if ((pos < 0) || (pos >= L->length))//유효한 범위값이 아닌지
		error((char*)"Index Error");
	else {//유효한 범위 값에 들어있게 되면 값을 삭제
		item = L->list[pos];
		for (i = pos; i < L->length - 1; i++)
		{
			L->list[i] = L->list[i + 1];
			L->list[i + 1] = 0;

		}
		L->length--;
		return item;

	}
}

// 리스트의 모든 요소 삭제
void clear(ArrayListType* L)
{
	// Fill your code
	int i;
	if (isEmpty(L))
		error((char*)"List is Empty");
	else {
		for (i = L->length - 2; i >= 0; i--)
		{
			L->list[i] = L->list[i + 1];//제일 마지막 인덱스부터 순차적으로  앞으로 밀어준다. 
			L->list[i + 1] = 0;//앞으로 밀어준 인덱스의 요소값을 0으로 만들어 삭제 시켜준다.
		}
		L->list[0] = 0;//마지막으로 0번째 위치 값에 0을 넣어주고 길이도 0으로 만들어준다.
		L->length = 0;
	}


}

// pos 위치의 요소를 item으로 교체
void replace(ArrayListType* L, int pos, element item)
{
	// Fill your code
	if (isEmpty(L))
		error((char*)"List is Empty");//만일 비어있다면 error 함수 호출
	else {
		L->list[pos] = item; //원하는 위치에 요소 삽입
	}
}

// item이 리스트에 있는지 검사
// 리스트에 있으면 1을 반환
// 그렇지 않으면 0을 반환
int isList(ArrayListType* L, element item)
{
	// Fill your code
	int i;
	for (i = 0; i <= L->length - 1; i++)
	{
		if (L->list[i] == item)return 1;
	}
	return 0;
}

// pos 위치의 요소를 반환
element getItem(ArrayListType* L, int pos)
{
	// Fill your code
	return L->list[pos];
}

// 리스트의 길이(항목의 개수)를 구함
int getLength(ArrayListType* L)
{
	// Fill your code

	return L->length;
}


int main()
{
	ArrayListType* plist;

	// ListType를 동적으로 생성하고 ListType를 가리키는 
	// 포인터를 함수의 파라미터로 전달한다.
	plist = (ArrayListType*)malloc(sizeof(ArrayListType));

	init(plist);
	// Fill your code
	insert(plist, 0, 10);
	insert(plist, 0, 20);
	insertFirst(plist, 5);
	insertLast(plist, 30);
	insert(plist, -1, 3);

	isFull(plist);
	display(plist);
	printf("LENGTH IS %d\n", getLength(plist));

	//15보다 작은 요소 삭제
	for (int i = 0; i < getLength(plist); i++)
	{
		if (plist->list[i] < 15) {
			delete (plist, i);
		}
	}
	//0의 항목을 1의 항목과 교체
	int temp1, temp0;
	temp0 = plist->list[0];
	temp1 = plist->list[1];
	replace(plist, 1, temp0);//얘내 때문에 오류가 난다!!!
	replace(plist, 0, temp1);

	display(plist);
	clear(plist);
	isEmpty(plist);


	free(plist);

	return 0;
}