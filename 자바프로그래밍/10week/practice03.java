package practice;

import java.util.Scanner;

interface Showable {
	void show(String s);
}

interface Pickable {
	char pick(String s1, int i);
}

interface Operable {
	int operator(int x, int y);
}

interface Newable {
	String getString(String s);
}

interface IntArray {
	int[] getArray(int size);
}

class Utils {

	int add(int a, int b) {
		return a + b;
	}
}

public class practice03 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);

		// Showable����
		System.out.printf("���� ����ϰ� ���� ���ڿ��� �����ÿ�>>");
		String m_s = sc.nextLine();// nextLine()�� ���� ������� ���� ĥ ������ �Է¹���
		Showable m_Showable = (s) -> System.out.println(s);
		m_Showable.show(m_s);

		// operable ���� �� Utils�� �̿��Ѵٴ°� implements�������� Ŭ�����ȿ� interface�� �����ϴ����� �𸣰����� �װ�
		// �ƴ� �� ���Ƽ� �̷��� ����ý��ϴ�.
		System.out.printf("���ϱ� ������ �� ���� �ΰ��� �Է��Ͻÿ�>>");
		int m_x = sc.nextInt();
		int m_y = sc.nextInt();
		Operable m_Operable = (x, y) -> {

			Utils m_Utils = new Utils();
			return m_Utils.add(x, y);
		};
		System.out.println(m_Operable.operator(m_x, m_y));

		// Pickable ����
		System.out.printf("���ڿ��� ���° �ε����� �������� �����ÿ�>>");
		String m_s1 = sc.next();// next()�� ���������� �ű���� ����
		int m_i = sc.nextInt();
		Pickable m_Pickable = (s1, i) -> {
			return s1.charAt(i); // charAt(i): ���ڿ��� i��° �ε��� ��ġ�� �ִ� �迭�� ��ȯ
			// 2�� �Է��Ͽ� ����°�� ��¥�� ���´ٴ°��� ���α׷��ֻ� �迭�� �ε����� �Ȱ��� ������ i-1���� �ʿ���� i�� �����ָ� ��
		};
		System.out.println(m_Pickable.pick(m_s1, m_i));

		// Newable ����
		// System.out.printf("���ڿ��� �Է��Ͻÿ�>>");

		Newable m_Newable = (s) -> {

			String N_s = new String("���");
			return N_s;
		};
		System.out.println(m_Newable.getString(m_s));

		// IntArray
		System.out.printf("������ �迭�� ������ �Է��Ͻÿ�>>");
		int m_size = sc.nextInt();
		IntArray m_IntArray = (size) -> {
			int[] A = new int[size];
			for (int i = 0; i < size; i++) {
				A[i] = 0;
			}
			return A;
		};

		int[] m_A = m_IntArray.getArray(m_size);

		for (int i = 0; i < m_size; i++) {
			System.out.println(m_A[i]);
		}

		sc.close();
	}
}
