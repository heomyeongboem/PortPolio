package practice;

import java.util.Scanner;

public class practice02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner scanner = new Scanner(System.in);

		System.out.print("�� ������ �����ڸ� �Է»��̿�>>");// �Է� �޴� ������ number_1, number_2, operator(������)
		int number_1 = scanner.nextInt();
		int number_2 = scanner.nextInt();
		char operator = scanner.next().charAt(0);

		switch (operator) {
		// ���ϱ� ����
		case '+':

			Add add = new Add(number_1, number_2);// ��ü ������ ����Ʈ �����ڿ��� �ٷ� ���� �Է¹�����, ����Ʈ ������ �ȿ� setValue �Լ��� ȣ���ϴ� �ڵ尡 �־�
													// setValue�Լ��� ���Ͽ� ���� ����
			System.out.println(add.calculate());// �߻�ȭ �޼ҵ�� ������ Ŭ�������� ���� �ٸ� ������� �۵�
			break;

		// ���� ����
		case '-':
			Sub sub = new Sub(number_1, number_2);
			System.out.println(sub.calculate());
			break;

		// ���ϱ� ����
		case '*':
			Mul mul = new Mul(number_1, number_2);
			System.out.println(mul.calculate());
			break;

		// ������ ����
		case '/':
			Div div = new Div(number_1, number_2);
			System.out.println(div.calculate());
			break;

		// �̻��� �� �Է½�
		default:

			System.out.printf("Wrong input");

		}

		scanner.close();
	}

}

//�߻�ȭ Ŭ����
abstract class Mom {

	public int a;// ������ Ŭ�����鿡�� �������� ����, �곻�� �߻�ȭ �ƴ�!! �ݺ����� �ƴϱ� ������ �̷��� �ۼ��ص� ��
	public int b;// ������ Ŭ�����鿡�� �������� ����, �곻�� �߻�ȭ �ƴ�!!

	abstract void setValue(int a, int b); // �߻�ȭ �޼ҵ�

	abstract int calculate(); // �߻�ȭ �޼ҵ�

}

class Add extends Mom {

	Add(int a, int b) {// ����Ʈ �����ڿ��� ���� �Է¹ް� �������
		setValue(a, b);// ����Ʈ �����ڿ��� setValue�Լ��� ȣ���Ͽ� �ٷ� �� �־���
	}

	void setValue(int a, int b) {
		this.a = a;
		this.b = b;
	}

	int calculate() {// ������ �Լ�
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
