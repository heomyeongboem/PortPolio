package practice;

import java.util.Scanner;

public class practice1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s;
		Scanner sc = new Scanner(System.in);

		System.out.println("���ڿ��� �Է��ϼ���");
		s = sc.nextLine();// next�� ������ ������ �� �̻��� �Է��� ���ǹ��ϴ�!!!
		int count = 0;

		// String�� �ѱ��ھ� �޾Ƽ� ������ ���°��� ��Ʊ� ������ char������ ���ڿ� ������ ���ش�.
		for (int i = 0; i < s.length(); i++) {

			char c = s.charAt(i);
			if (c >= 'A' && c <= 'Z') {
				count++;
			}
		}
		System.out.println("�빮���� ������" + count + "�� �Դϴ�");
		sc.close();
	}

}
