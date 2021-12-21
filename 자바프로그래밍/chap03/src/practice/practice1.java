package practice;

//문제 내주신 순서대로 practice 1, 2, 3, 4, 5 로 만들었습니다.

import java.util.Scanner;

public class practice1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		System.out.printf("점수를 입력하세요:");

		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();

		if (x >= 90)
			System.out.println("A");
		else if (x >= 80)
			System.out.println("B");
		else if (x >= 70)
			System.out.println("C");
		else if (x >= 60)
			System.out.println("D");
		else
			System.out.println("F");

		sc.close();
	}

}
