package practice;

import java.util.Scanner;

public class practice1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		TestCalculator TC = new TestCalculator();
		TC.inputFunction();
	}

}

class Calculator {// ���ڸ� �޾ƿ� ������ Field ����
	int x;
	int y;

	public Calculator(int a, int b)// Constructor ����
	{
		x = a;
		y = b;
	}

	int Add() {
		return x + y;
	}

	int Sub() {
		return x - y;
	}

	int Mul() {
		return x * y;
	}

	int Div() {
		return x / y;
	}

	int Rem() {
		return x % y;
	}
}

class TestCalculator {

	void inputFunction() {

		Scanner sc = new Scanner(System.in);

		System.out.println("���ڸ� �Է��ϼ���");
		int c = sc.nextInt();

		System.out.println("�����ڸ� �Է��ϼ���");
		char operator = sc.next().charAt(0);

		System.out.println("���ڸ� �Է��ϼ���");
		int d = sc.nextInt();
		Calculator Cc = new Calculator(c, d);

		switch (operator) {

		case '+':
			System.out.printf("%d %c %d = %d\n", c, operator, d, Cc.Add());
			break;

		case '-':
			System.out.printf("%d %c %d = %d\n", c, operator, d, Cc.Sub());
			break;

		case '*':

			System.out.printf("%d %c %d = %d\n", c, operator, d, Cc.Mul());
			break;

		case '/':

			System.out.printf("%d %c %d = %d\n", c, operator, d, Cc.Div());
			break;

		case '%':

			System.out.printf("%d %c %d = %d\n", c, operator, d, Cc.Rem());
			break;
		default:
			System.out.printf("�߸��� �����Դϴ�");
			break;

		}

		sc.close();

	}

}