package practice;

import java.util.ArrayList;
import java.util.Scanner;

public class practice01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<String> a = new ArrayList<String>();

		Scanner sc = new Scanner(System.in);
		// �� �ֱ�
		for (int i = 0; i < 4; i++) {
			System.out.print("�̸��� �Է��ϼ���>>");
			String s = sc.next();
			a.add(s);// ArrayList<String> a �� �� s �ֱ�
		}
		// �� ���
		for (int i = 0; i < a.size(); i++) {
			String name = a.get(i); // ArrayList�� i��° ���ڿ� ������
			System.out.print(name + " ");
		}
		sc.close();
	}

}
