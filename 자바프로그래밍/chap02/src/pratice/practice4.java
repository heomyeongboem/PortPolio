package pratice;

import java.util.Scanner;

public class practice4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		double t;// �Է� ���� �ð�
		double x;// ��ġ
		double a = 9.81;

		Scanner sc = new Scanner(System.in);
		t = sc.nextDouble();

		x = 0.5 * a * t * t;// ��ü�� �󸶳� �̵��ߴ��Ŀ� ���� ������ 1/2 *a*t^2 (a=v/t ==> v=t*a�̹Ƿ�)

		if (x > 1000)
			x = 1000;// 1000m���� ����߷ȴµ� 1000m �̻��� �� ���� �����Ƿ� 1000m �̻�� 1000m�� ����

		else {
			System.out.printf("%fm", x);// �Է� �������� ���� �Ŀ� �����Ͽ� ��ġ ���� ���
		}
		sc.close();
	}

}
