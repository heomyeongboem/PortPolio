package practice;

import java.util.Scanner;

public class practice5 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		System.out.println("�� ���α׷��� 0���� 100������ ������ ���ڸ� �������ݴϴ�.");
		System.out.println("���Բ��� ���ڸ� �Է������� �Է��� ������ ������ ���� ������ 'Up' ������ 'Down'�̶�� ���ɴϴ�");
		System.out.println("�׷� ���� �ð� �ǽñ⸦ �ٶ�ڽ��ϴ�.");

		Scanner sc = new Scanner(System.in);

		double randomValue = Math.random();
		int intValue = (int) (randomValue * 100 + 1);// *100�� �ִ��� 100���� ����

		System.out.printf("���ڸ� �Է��ϼ���:");
		int number = sc.nextInt();

		while (number != intValue) {

			if (number < intValue)
				System.out.println("Up!");// �Էµ� ������ ������ ������ Ŭ��
			else
				System.out.println("Down!");

			System.out.printf("���ڸ� �Է��ϼ���:");
			number = sc.nextInt();

		}

		System.out.println("�½��ϴ�. ���ڴ� " + intValue + "�Դϴ�.");
		sc.close();
	}

}
