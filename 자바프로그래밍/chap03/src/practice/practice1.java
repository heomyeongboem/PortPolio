package practice;

//���� ���ֽ� ������� practice 1, 2, 3, 4, 5 �� ��������ϴ�.

import java.util.Scanner;

public class practice1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		System.out.printf("������ �Է��ϼ���:");

		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();

		if (x >= 90)
			System.out.println("A");
		else if (x >= 80)
			System.out.println("B");
		else if (x >= 70)
			System.out.println("C");
		else if (x >= 60)
			System.out.println("D");
		else
			System.out.println("F");

		sc.close();
	}

}
