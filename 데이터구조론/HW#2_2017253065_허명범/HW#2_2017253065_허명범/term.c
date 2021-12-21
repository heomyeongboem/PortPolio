#include <stdio.h>
#pragma warning ( disable : 4996 )

#define MAX_TERMS 20

typedef struct {    // 구조체 term 정의
    float coef; // 다항식의 각 항의 계수를 저장할 변수
    int exp;    // 다항식의 각 항의 차수를 저장할 변수
} term;

int A_length = 3;
int B_length = 3;
int C_length = 0;

float isZero(term* s) //더이상 항이 있는지 없는지를 판단하는 함수
{//첫번째 배열의 계수가 0일시 항이 없다고 판단
    if (s->coef == 0) {
        return 1;
    }
    else return 0;
}

int maxExp(term* k) //최고차항을 반환하는 함수
{
    return k->exp;//만일 작동 안된다면 1넣은다음 coef 함수에서 -1헤줘야한다.
}

float coef(term* d, int f)//그 차수의 계수를 알려주는 함수 어짜피 맨 앞에 있는 값이 최고차항이기 때문에 제일 앞에 있는 값의 계수를 보내준다.
{
    return d->coef;
}

void delTermA(term* z) {//A리스트에 맨 앞에 항목을 삭제

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

void delTermB(term* o) {//B리스트에 맨 앞에 항목을 삭제



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

    if (isZero(p))//데이터가 존재 하지 않아 첫번째에 값을 저장
    {
        p->coef = a;
        p->exp = e;
    }
    else//데이터 존재시 앞에 있는 값들을 뒤로 밀어주고 제일 앞에 방금 들어온 값을 넣어준다.
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

void addTerm(term* A, term* B, term* C)//다항식 덧셈 함수
{
    // Fill your code
    float sum;
    int i = 0;
    while (!isZero(A) && !isZero(B)) {
        //A와B 둘중 하나라도 리스트값이 존재하지 않을때까지 반복
        switch (COMPARE(maxExp(A), maxExp(B)))//비교함수 COMPARE
        {

        case 1: addTerm1(C, coef(B, maxExp(B)), maxExp(B));//B가 클 때 B의 계수와 차수를 C에 넣어줌
            delTermB(B);
            break;


        case 0:
            sum = coef(A, maxExp(A)) + coef(B, maxExp(B));//A와 B의 차수가 같을 때 두 다항식의 계수를 더해줌 후 C에 대입
            if (sum != 0) {
                addTerm1(C, sum, maxExp(A));
            }
            delTermA(A);
            delTermB(B);
            break;

        case -1:    addTerm1(C, coef(A, maxExp(A)), maxExp(A)); //A차수가 클때 A의 다항식 계수를 C에 넣어줌
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

    //A리스트 다시 값 넣어줌
    A[0].coef = 3;
    A[0].exp = 19;

    A[1].coef = 4;
    A[1].exp = 5;

    A[2].coef = 1;
    A[2].exp = 0;


    //B리스트 다시 값 넣어줌
    B[0].coef = 5;
    B[0].exp = 8;

    B[1].coef = 7;
    B[1].exp = 5;

    B[2].coef = 1;
    B[2].exp = 1;

    //내림차순인 bubble 정렬 intime 대신 exp를 넣으므로써 차수가 높은값부터 내림차순으로 나오게 만들었습니다.
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