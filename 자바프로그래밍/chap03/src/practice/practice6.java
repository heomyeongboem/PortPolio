package practice;

import java.util.Scanner;

public class practice6 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int count = 0;

		Scanner sc = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			double randomValue_1 = Math.random();
			int intValue_1 = (int) (randomValue_1 * 10);// �ִ��� 9���� ������ֱ� ���� *10�� ���־����ϴ�. *0999999*10=9.99999=>9

			double randomValue_2 = Math.random();
			int intValue_2 = (int) (randomValue_2 * 10);

			if (intValue_1 < intValue_2) {// temp���� ����Ͽ� ���� �ڿ� ������ ������ Ŭ �� �տ� ������ �ڿ� ������ ���� �ٲٵ��� ���־����ϴ�.
				int temp;
				temp = intValue_1;
				intValue_1 = intValue_2;
				intValue_2 = temp;
			}

			System.out.println(+intValue_1 + "-" + intValue_2 + "=");
			int answer = sc.nextInt();
			if (answer == (intValue_1 - intValue_2)) {
				System.out.println("�����Դϴ�.");
				count++;
			} else {
				System.out.println("Ʋ�Ƚ��ϴ�. ������" + (intValue_1 - intValue_2) + "�Դϴ�.");

			}

		}

		System.out.println("��" + count + "�� �����̽��ϴ�");

		sc.close();

	}

}
