package practice;

public class practice2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] s = { 1, 2 };

		System.out.printf("��ȯ��:");
		for (int i = 0; i < s.length; i++) {
			System.out.printf(" %d", s[i]);
		}

		// ��ȯ ���ִ� ��ɹ�
		int temp;
		temp = s[0];
		s[0] = s[1];
		s[1] = temp;

		System.out.println();
		System.out.printf("��ȯ��:");
		for (int i = 0; i < s.length; i++) {
			System.out.printf(" %d", s[i]);
		}

	}

}
