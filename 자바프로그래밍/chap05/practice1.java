package practice;

import java.util.Scanner;

public class practice1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int[] x = { 0, 0, 0, 0, 0, 1, 1, 1, 0, 0 };// �¼�
		int Reservation_First = 1;// ���� �ݺ����� ������ �ִ� Ű�����Դϴ�.
		// ó������ 1�� �־� ó������ ������ �� �� �ְ� ������ݴϴ�.

		while (Reservation_First == 1) {
			System.out.printf("�¼��� �����Ͻðڽ��ϱ�? (1 �Ǵ� 0)");
			int Reservation = sc.nextInt();
			if (Reservation == 1) {
				System.out.println("������ ���� ���´� ������ �����ϴ�.");
				System.out.println("--------------------------");// 26���Դϴ�.
				for (int i = 0; i < x.length; i++) {
					System.out.printf("%d ", i);
				}
				System.out.println();
				System.out.println("--------------------------");// 26���Դϴ�.
				for (int i = 0; i < x.length; i++) {
					System.out.printf("%d ", x[i]);
				}
				while (Reservation == 1) { // �ݺ����� ����Ͽ� �����Ϸ��µ�
					// �̹� �� �ڸ��� ����� �ڸ���� �ٽ� �ް� �մϴ�. ���� �������Դϱ�?��� �������޽��ϴ�.
					System.out.println();
					System.out.printf("�� ��° �¼��� �����Ͻðڽ��ϱ�?");
					int num = sc.nextInt();// ������ �¼� ��ȣ
					if (x[num] != 1) {// 1���ڸ��� x�迭������ 0��° �ε������� num-1���ݴϴ�.
						// ���� 1�� �ƴ϶�°��� ����ȵǾ������Ƿ� ������ �� �ֽ��ϴ�.
						x[num] = 1;
						System.out.printf("%d", num);
						System.out.println("����Ǿ����ϴ�.");
						Reservation = 0;// �ݺ��� ������ ���
						break;
					} else {// �̹� ����� �ڸ��̹Ƿ� �ٽ� �޽��ϴ�.
						System.out.println("�̹� ����� �ڸ��Դϴ�.");
						Reservation = 0;// 1�̸� �ݺ����� �ٽ� ���⶧���� �ٽ� �����Ҽ� �ְ�
						// 0�̸� �ݺ��� ������ ������Ű�� ���ϹǷ� �ݺ����� �������ɴϴ�.

					}

				}
			}

			else {// �����ϱ� ���� ����̹Ƿ�
				Reservation_First = 0;// �ý��� ������¸� ������ݴϴ�.
			}

		}

		System.out.printf("�ý����� ����Ǿ����ϴ�.");
		sc.close();
	}

}
