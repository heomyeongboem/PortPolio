package pratice;

import java.util.Scanner;

public class practice3 {

	public static void main(String[] args) {

		int num;
		Scanner sc = new Scanner(System.in);
		num = sc.nextInt();
		System.out.printf((num > 0) ? "���" : (num == 0) ? "0" : "����");// ���� �����ڸ� ã�ƺ��� �� ����� ��ɹ����ٿ� �� 3���� �����ִ� �ٴ� ����
																		// �˰ԵǾ����ϴ�.
		sc.close();
	}
}
