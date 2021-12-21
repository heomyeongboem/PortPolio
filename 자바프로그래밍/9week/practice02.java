package practice;

import java.util.Scanner;

public class practice02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner scanner = new Scanner(System.in);

		System.out.print("두 정수와 연산자를 입력사이오>>");// 입력 받는 변수들 number_1, number_2, operator(연산자)
		int number_1 = scanner.nextInt();
		int number_2 = scanner.nextInt();
		char operator = scanner.next().charAt(0);

		switch (operator) {
		// 더하기 연산
		case '+':

			Add add = new Add(number_1, number_2);// 객체 생성시 디폴트 연산자에서 바로 값을 입력받으며, 디폴트 연산자 안에 setValue 함수를 호출하는 코드가 있어
													// setValue함수를 통하여 값을 저장
			System.out.println(add.calculate());// 추상화 메소드로 각각의 클래스에서 각각 다른 방식으로 작동
			break;

		// 빼기 연산
		case '-':
			Sub sub = new Sub(number_1, number_2);
			System.out.println(sub.calculate());
			break;

		// 곱하기 연산
		case '*':
			Mul mul = new Mul(number_1, number_2);
			System.out.println(mul.calculate());
			break;

		// 나누기 연산
		case '/':
			Div div = new Div(number_1, number_2);
			System.out.println(div.calculate());
			break;

		// 이상한 값 입력시
		default:

			System.out.printf("Wrong input");

		}

		scanner.close();
	}

}

//추상화 클래스
abstract class Mom {

	public int a;// 각각의 클래스들에서 저장해줄 변수, 얘내는 추상화 아님!! 반복문이 아니기 때문에 이렇게 작성해도 됌
	public int b;// 각각의 클래스들에서 저장해줄 변수, 얘내는 추상화 아님!!

	abstract void setValue(int a, int b); // 추상화 메소드

	abstract int calculate(); // 추상화 메소드

}

class Add extends Mom {

	Add(int a, int b) {// 디폴트 생성자에서 값을 입력받게 만들어줌
		setValue(a, b);// 디폴트 생성자에서 setValue함수를 호출하여 바로 값 넣어줌
	}

	void setValue(int a, int b) {
		this.a = a;
		this.b = b;
	}

	int calculate() {// 연산자 함수
		return a + b;
	}

}

class Sub extends Mom {

	Sub(int a, int b) {
		setValue(a, b);
	}

	void setValue(int a, int b) {
		this.a = a;
		this.b = b;
	}

	int calculate() {
		return a - b;
	}

}

class Mul extends Mom {

	Mul(int a, int b) {
		setValue(a, b);
	}

	void setValue(int a, int b) {
		this.a = a;
		this.b = b;
	}

	int calculate() {
		return a * b;
	}

}

class Div extends Mom {

	Div(int a, int b) {
		setValue(a, b);
	}

	void setValue(int a, int b) {
		this.a = a;
		this.b = b;
	}

	int calculate() {
		return a / b;
	}

}
