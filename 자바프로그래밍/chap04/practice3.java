package practice;

public class practice3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// �迭 ����
		double[] s = { 1, 9, 4.5, 6.6, 5.7, -4.5 };

		// �������� ==> ū����� �ڷ� �������� �ڸ��� �����༭ �ڿ��� ������ �ڸ��� �����ִ� ����
		for (int i = 0; i < s.length - 1; i++) {
//i<s.length - 1�� if(s[j] > s[j + 1])�� s[j + 1]������ �̷��� �ۼ��Ͽ����ϴ�.
			for (int j = 0; j < s.length - 1 - i; j++) {

				if (s[j] > s[j + 1]) {
					double temp = s[j];
					s[j] = s[j + 1];
					s[j + 1] = temp;
				}

			}

		}

		// ���
		for (int i = 0; i < s.length; i++) {
			System.out.printf("%.1f ", s[i]);// �Ҽ��� ���ڸ����� ���ϱ� ���� .1f�� �ۼ��Ͽ����ϴ�.
		}

	}

}
