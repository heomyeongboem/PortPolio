package practice;

public class practice2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] s = { 1, 2 };

		System.out.printf("교환전:");
		for (int i = 0; i < s.length; i++) {
			System.out.printf(" %d", s[i]);
		}

		// 교환 해주는 명령문
		int temp;
		temp = s[0];
		s[0] = s[1];
		s[1] = temp;

		System.out.println();
		System.out.printf("교환후:");
		for (int i = 0; i < s.length; i++) {
			System.out.printf(" %d", s[i]);
		}

	}

}
