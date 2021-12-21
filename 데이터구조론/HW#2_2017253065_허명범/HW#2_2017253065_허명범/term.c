#include <stdio.h>
#pragma warning ( disable : 4996 )

#define MAX_TERMS 20

typedef struct {    // ����ü term ����
    float coef; // ���׽��� �� ���� ����� ������ ����
    int exp;    // ���׽��� �� ���� ������ ������ ����
} term;

int A_length = 3;
int B_length = 3;
int C_length = 0;

float isZero(term* s) //���̻� ���� �ִ��� �������� �Ǵ��ϴ� �Լ�
{//ù��° �迭�� ����� 0�Ͻ� ���� ���ٰ� �Ǵ�
    if (s->coef == 0) {
        return 1;
    }
    else return 0;
}

int maxExp(term* k) //�ְ������� ��ȯ�ϴ� �Լ�
{
    return k->exp;//���� �۵� �ȵȴٸ� 1�������� coef �Լ����� -1������Ѵ�.
}

float coef(term* d, int f)//�� ������ ����� �˷��ִ� �Լ� ��¥�� �� �տ� �ִ� ���� �ְ������̱� ������ ���� �տ� �ִ� ���� ����� �����ش�.
{
    return d->coef;
}

void delTermA(term* z) {//A����Ʈ�� �� �տ� �׸��� ����

    if (A_length == 0) {
        z->coef = 0;
        z->exp = 0;
    }

    else if (A_length != 0)
    {
        for (int i = 1; i <= A_length - 1; i++) {
            z[i - 1].coef = z[i].coef;
            z[i - 1].exp = z[i].exp;
        }
        z[A_length - 1].coef = 0;
        z[A_length - 1].exp = 0;
        A_length--;
    }
}

void delTermB(term* o) {//B����Ʈ�� �� �տ� �׸��� ����



    if (B_length != 0)
    {
        for (int i = 1; i <= B_length - 1; i++) {
            o[i - 1].coef = o[i].coef;
            o[i - 1].exp = o[i].exp;
        }
        o[B_length - 1].coef = 0;
        o[B_length - 1].exp = 0;
        B_length--;
    }
    else if (B_length == 0) {
        o->coef = 0;
        o->exp = 0;
    }

}

void addTerm1(term* p, float a, int e)
{

    if (isZero(p))//�����Ͱ� ���� ���� �ʾ� ù��°�� ���� ����
    {
        p->coef = a;
        p->exp = e;
    }
    else//������ ����� �տ� �ִ� ������ �ڷ� �о��ְ� ���� �տ� ��� ���� ���� �־��ش�.
    {
        for (int i = C_length - 1; i >= 0; i--)
        {

            p[i + 1].coef = p[i].coef;

            p[i + 1].exp = p[i].exp;
        }
        p->coef = a;
        p->exp = e;
    }
    C_length++;

}


int COMPARE(int a, int b)
{
    if (a > b)return -1;
    else if (a == b) return 0;
    else if (a < b)return 1;
}

void addTerm(term* A, term* B, term* C)//���׽� ���� �Լ�
{
    // Fill your code
    float sum;
    int i = 0;
    while (!isZero(A) && !isZero(B)) {
        //A��B ���� �ϳ��� ����Ʈ���� �������� ���������� �ݺ�
        switch (COMPARE(maxExp(A), maxExp(B)))//���Լ� COMPARE
        {

        case 1: addTerm1(C, coef(B, maxExp(B)), maxExp(B));//B�� Ŭ �� B�� ����� ������ C�� �־���
            delTermB(B);
            break;


        case 0:
            sum = coef(A, maxExp(A)) + coef(B, maxExp(B));//A�� B�� ������ ���� �� �� ���׽��� ����� ������ �� C�� ����
            if (sum != 0) {
                addTerm1(C, sum, maxExp(A));
            }
            delTermA(A);
            delTermB(B);
            break;

        case -1:    addTerm1(C, coef(A, maxExp(A)), maxExp(A)); //A������ Ŭ�� A�� ���׽� ����� C�� �־���
            delTermA(A);
            break;


        }



    }

    if (!isZero(B))
    {
        addTerm1(C, coef(B, maxExp(B)), maxExp(B));
        delTermA(B);
    }

    else if (!isZero(A))
    {
        addTerm1(C, coef(A, maxExp(A)), maxExp(A));
        delTermA(A);
    }

    //A����Ʈ �ٽ� �� �־���
    A[0].coef = 3;
    A[0].exp = 19;

    A[1].coef = 4;
    A[1].exp = 5;

    A[2].coef = 1;
    A[2].exp = 0;


    //B����Ʈ �ٽ� �� �־���
    B[0].coef = 5;
    B[0].exp = 8;

    B[1].coef = 7;
    B[1].exp = 5;

    B[2].coef = 1;
    B[2].exp = 1;

    //���������� bubble ���� intime ��� exp�� �����Ƿν� ������ ���������� ������������ ������ ��������ϴ�.
    int N = 5;
    for (int h = N - 1; h >= 1; h--) {
        for (int j = 0; j < h; j++) {
            if (C[j].exp < C[j + 1].exp) {
                int exptemp = C[j].exp;
                float coeftemp = C[j].coef;

                C[j].exp = C[j + 1].exp;
                C[j].coef = C[j + 1].coef;

                C[j + 1].exp = exptemp;
                C[j + 1].coef = coeftemp;

            }
        }
    }

}


void printTerm(term* p) {
    int i = 0;
    while (p[i].exp != 0 || p[i].coef != 0) {
        printf("%3.0fx^%d", p[i].coef, p[i].exp);
        i++;
        if (p[i].exp != -1 && p[i].coef > 0)
            printf(" +");
    }
    printf("\n");
}

int main() {
    term A[MAX_TERMS] = { {3,19}, {4,5}, {1,0} };
    term B[MAX_TERMS] = { {5,8}, {7,5}, {1,1} };
    term C[MAX_TERMS] = { 0 };
    addTerm(A, B, C);

    printf("\n A(x)="); printTerm(A);
    printf("\n B(x)="); printTerm(B);
    printf("\n C(x)="); printTerm(C);

    return 0;
}