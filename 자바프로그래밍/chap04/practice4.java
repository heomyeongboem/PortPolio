package practice;

import java.util.Scanner;

public class practice4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[][] a = new int[3][3];// a��� ����
		int[][] b = new int[3][3];// b��� ����
		Scanner sc = new Scanner(System.in);

		// a��Ŀ� �� �Է�
		System.out.println("a����� �Է��ϼ���.a����� 3*3����Դϴ�");
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[i].length; j++) {
				a[i][j] = sc.nextInt();
			}
		}

		// b��Ŀ� �� �Է�
		System.out.println("b����� �Է��ϼ���.b����� 3*3����Դϴ�");
		for (int i = 0; i < b.length; i++) {
			for (int j = 0; j < b[i].length; j++) {
				b[i][j] = sc.nextInt();
			}
		}

		sc.close();

		// a���+b���
		System.out.println("a���+b���");
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[i].length; j++) {
				System.out.printf("%d ", a[i][j] + b[i][j]);
			}
			// ����ٰ� println()�� ���� ������ ���� �ٲ𶧸��� ���� �ٲ��ָ� �̻� �� ���Ƽ� �׷����ϴ�.
			System.out.println();
		}

	}

}
