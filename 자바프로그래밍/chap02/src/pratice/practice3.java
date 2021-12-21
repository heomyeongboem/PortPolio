package pratice;

import java.util.Scanner;

public class practice3 {

	public static void main(String[] args) {

		int num;
		Scanner sc = new Scanner(System.in);
		num = sc.nextInt();
		System.out.printf((num > 0) ? "양수" : (num == 0) ? "0" : "음수");// 삼항 연산자를 찾아보니 그 말대로 명령문한줄에 항 3개를 끼워넣는 다는 것을
																		// 알게되었습니다.
		sc.close();
	}
}
