package practice;

public class practice4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		for (int i = 2; i <= 9; i++) {
			if (i > 2)
				System.out.println();// 단이 바뀌면 줄이 바뀌도록 설정했습니다.
			for (int j = 1; j <= 9; j++) {
				System.out.printf("%d*%d=%d ", i, j, i * j);

			}

		}

	}

}