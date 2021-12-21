package practice;

import java.util.Scanner;

public class practice6 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int count = 0;

		Scanner sc = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			double randomValue_1 = Math.random();
			int intValue_1 = (int) (randomValue_1 * 10);// 최댓값을 9까지 만들어주기 위해 *10을 해주었습니다. *0999999*10=9.99999=>9

			double randomValue_2 = Math.random();
			int intValue_2 = (int) (randomValue_2 * 10);

			if (intValue_1 < intValue_2) {// temp문을 사용하여 만일 뒤에 생성된 난수가 클 시 앞에 난수와 뒤에 난수의 값을 바꾸도록 해주었습니다.
				int temp;
				temp = intValue_1;
				intValue_1 = intValue_2;
				intValue_2 = temp;
			}

			System.out.println(+intValue_1 + "-" + intValue_2 + "=");
			int answer = sc.nextInt();
			if (answer == (intValue_1 - intValue_2)) {
				System.out.println("정답입니다.");
				count++;
			} else {
				System.out.println("틀렸습니다. 정답은" + (intValue_1 - intValue_2) + "입니다.");

			}

		}

		System.out.println("총" + count + "개 맞으셨습니다");

		sc.close();

	}

}
