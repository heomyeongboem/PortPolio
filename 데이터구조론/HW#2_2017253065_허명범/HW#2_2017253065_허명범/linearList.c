
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

#define MAX_SIZE 100		// �迭�� �ִ� ũ��

typedef int element;
typedef struct {
	element list[MAX_SIZE];	// �迭 ����
	int length;		// ���� �迭�� ����� �ڷ���� ����
}ArrayListType;

// ���� ó�� �Լ�
void error(char* message)
{
	printf("%s\n", message);
}

// ����Ʈ �ʱ�ȭ
void init(ArrayListType* L)
{
	L->length = 0;

}

// �� ����Ʈ �˻�
// ����Ʈ�� ��� ������ 1�� ��ȯ
// �׷��� ������ 0�� ��ȯ
int isEmpty(ArrayListType* L)
{
	if (L->length == 0) {
		printf("IS EMPTY\n");
		return 1;
	}
	else return 0;
}

// ����Ʈ�� ��ȭ������ �˻�
// ����Ʈ�� ������ ������ 1�� ��ȯ
// �׷��� ������ 0�� ��ȯ
int isFull(ArrayListType* L)
{
	return L->length == MAX_SIZE;
}

// ����Ʈ�� ��� ��� ���
void display(ArrayListType* L)
{
	int i;
	printf("===Print Lists===\n");
	for (i = 0; i < L->length; i++)
		printf("ArrayList[%d]: %d\n", i, L->list[i]);
}

// ���� �Լ� 
// pos: �����ϰ��� �ϴ� ��ġ
// item: �����ϰ��� �ϴ� �ڷ�
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
		printf("ArrayList[%d]�� %d ����\n", pos, item);
		L->length++;
	}
}

// ����Ʈ �� �տ� ��� ����
void insertFirst(ArrayListType* L, element item)
{
	// Fill your code
	int i;
	if (isFull(L))
		error((char*)"List is Full!");

	else {
		for (i = (L->length - 1); i >= 0; i--)//�� �� �ε������� �� �� �ε����� 0���� �ڷ� �о��ش�.
			L->list[i + 1] = L->list[i];

		L->list[0] = item;
		printf("ArrayList[0]�� %d ����\n", item);
		L->length++;
	}
}

// ����Ʈ �� ���� ��� ����
void insertLast(ArrayListType* L, element item)
{
	// Fill your code

	if (isFull(L))
		error((char*)"List is Full!");

	else {
		L->list[L->length] = item;
		printf("ArrayList[%d]�� %d ����\n", L->length, item);
		L->length++;
	}
}

// ���� �Լ�
// pos: �����ϰ��� �ϴ� ��ġ
// ��ȯ��: �����Ǵ� �ڷ�
element delete(ArrayListType* L, int pos)
{
	// Fill your code
	int i;
	element item;
	if (isEmpty(L))//����ִ���
		error((char*)"List is Empty");
	else if ((pos < 0) || (pos >= L->length))//��ȿ�� �������� �ƴ���
		error((char*)"Index Error");
	else {//��ȿ�� ���� ���� ����ְ� �Ǹ� ���� ����
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

// ����Ʈ�� ��� ��� ����
void clear(ArrayListType* L)
{
	// Fill your code
	int i;
	if (isEmpty(L))
		error((char*)"List is Empty");
	else {
		for (i = L->length - 2; i >= 0; i--)
		{
			L->list[i] = L->list[i + 1];//���� ������ �ε������� ����������  ������ �о��ش�. 
			L->list[i + 1] = 0;//������ �о��� �ε����� ��Ұ��� 0���� ����� ���� �����ش�.
		}
		L->list[0] = 0;//���������� 0��° ��ġ ���� 0�� �־��ְ� ���̵� 0���� ������ش�.
		L->length = 0;
	}


}

// pos ��ġ�� ��Ҹ� item���� ��ü
void replace(ArrayListType* L, int pos, element item)
{
	// Fill your code
	if (isEmpty(L))
		error((char*)"List is Empty");//���� ����ִٸ� error �Լ� ȣ��
	else {
		L->list[pos] = item; //���ϴ� ��ġ�� ��� ����
	}
}

// item�� ����Ʈ�� �ִ��� �˻�
// ����Ʈ�� ������ 1�� ��ȯ
// �׷��� ������ 0�� ��ȯ
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

// pos ��ġ�� ��Ҹ� ��ȯ
element getItem(ArrayListType* L, int pos)
{
	// Fill your code
	return L->list[pos];
}

// ����Ʈ�� ����(�׸��� ����)�� ����
int getLength(ArrayListType* L)
{
	// Fill your code

	return L->length;
}


int main()
{
	ArrayListType* plist;

	// ListType�� �������� �����ϰ� ListType�� ����Ű�� 
	// �����͸� �Լ��� �Ķ���ͷ� �����Ѵ�.
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

	//15���� ���� ��� ����
	for (int i = 0; i < getLength(plist); i++)
	{
		if (plist->list[i] < 15) {
			delete (plist, i);
		}
	}
	//0�� �׸��� 1�� �׸�� ��ü
	int temp1, temp0;
	temp0 = plist->list[0];
	temp1 = plist->list[1];
	replace(plist, 1, temp0);//�곻 ������ ������ ����!!!
	replace(plist, 0, temp1);

	display(plist);
	clear(plist);
	isEmpty(plist);


	free(plist);

	return 0;
}