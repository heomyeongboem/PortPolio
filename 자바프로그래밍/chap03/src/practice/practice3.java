package practice;

import java.util.Scanner;

public class practice3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		char operator;
		int num_1, num_2;

		Scanner sc = new Scanner(System.in);

		System.out.println("���Ͻô� ������ �Է��ϼ���:");
		operator = sc.next().charAt(0);// next�Լ������� char�� ���� �� ���� ������ charAt(0)�� �߰��� ��������ϴ�. (�˻� �غ����)

		System.out.println("���Ͻô� ���� �ΰ��� �Է��ϼ���:");
		num_1 = sc.nextInt();
		num_2 = sc.nextInt();

		switch (operator) {

		case '+':
			System.out.printf("%d+%d=%d", num_1, num_2, num_1 + num_2);
			break;

		case '-':
			System.out.printf("%d-%d=%d", num_1, num_2, num_1 - num_2);
			break;

		case '*':
			System.out.printf("%d*%d=%d", num_1, num_2, num_1 * num_2);
			break;

		case '/':
			System.out.printf("%d/%d=%d", num_1, num_2, num_1 / num_2);
			break;

		case '%':
			System.out.println(+num_1 + "%" + num_2 + "=" + (num_1 % num_2));
			break;

		default:

			System.out.printf("Wrong input");

		}

		sc.close();
	}

}
