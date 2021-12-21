package practice;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class practice03 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		m_Stack S = new m_Stack();

		System.out.print("�� ���� ���� ������ ũ�� �Է� >>");
		S.SetterStackSize(sc.nextInt());

		String str;// �ƹ��� ���� do while���ȿ��� �Է��� �ѹ��� �ް� ¥���� �̹���ۿ� �������ϴ�.

		do {
			System.out.print("���ڿ� �Է�>>");
			str = sc.next();

			if (str.equals("stop")) {
				break;
			}

			else if (S.FullStackSize() == S.StackSize()) {// ���簳���� ��ü������ ������ ���� (��������2)
				System.out.println("������ �� ���� Ǫ�� �Ұ�!");
				// break;// ���簹���� ���������� ������ ����}
			} else {
				S.push(str);
				S.SetterStackSize();
			}

		} while (!str.equals("stop")); // stop�Ǹ� ���� (��������1)

		for (int i = 0; i < S.StackSize(); i++) {
			System.out.printf(" %s", S.peek());
		}
		sc.close();
	}

}

interface Stack {

	int StackSize();// ���� ���ÿ� ����� ���� ���� �޼ҵ�

	int FullStackSize();// ������ ��ü ���� ������ ���� ����

	void push(String a);// ������ top�� ���ڿ� ����

	String peek();// ������ top�� ����� ���ڿ� ����

}

class m_Stack implements Stack {

	List<String> str = new ArrayList<String>();// �����迭�� �Ҵ�

	int top = -1;
	int number = 0;// ���簹��
	int Full;

	// ���簳���� �־���
	public void SetterStackSize() {
		number++;
	}

	// ���� ���ÿ� ����� ���� ���� �޼ҵ�
	@Override
	public int StackSize() {
		return number;
	}

	// ��ü�������� �־���
	public void SetterStackSize(int a) {
		this.Full = a;
	}

	// ������ ��ü ���� ������ ���� ����
	@Override
	public int FullStackSize() {
		return Full;
	}

	// ������ top�� ���ڿ� ����
	@Override
	public void push(String a) {
		top++;
		str.add(a);// arrayList ��ü�� �߰����ִ� �޼ҵ�� �����迭�� ArrayList�� ���������ν� top�� ����������
	}// �������� peek�Լ����� top�� ����� �� �ֵ��� top++�� ���ݴϴ�.

	// ������ top�� ����� ���ڿ� ����
	@Override
	public String peek() {

		return str.get(top--);// top�� �ε����� �����ɴϴ�.

	}

}
