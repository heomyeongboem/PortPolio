package practice;

import java.util.Scanner;

public class practice2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);

		System.out.println("1:����, 2:����, 3:����, 4:������, 5:������ ����");
		int z = sc.nextInt();

		System.out.printf("������ ���ϴ� ���� �ΰ��� �Է��ϼ���:");
		int x = sc.nextInt();
		int y = sc.nextInt();

		if (z == 1)
			System.out.printf("%d+%d=%d", x, y, x + y);
		if (z == 2)
			System.out.printf("%d-%d=%d", x, y, x - y);
		if (z == 3)
			System.out.printf("%d*%d=%d", x, y, x * y);
		if (z == 4)
			System.out.printf("%d/%d=%d", x, y, x / y);
		if (z == 5)
			System.out.println(+x + "%" + y + "=" + (x % y));
		else
			System.out.println("Wrong input");
		sc.close();
	}

}
