package practice;

import java.util.Scanner;

public class practice5 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		System.out.println("이 프로그램은 0에서 100사이의 무작위 숫자를 생성해줍니다.");
		System.out.println("고객님께서 숫자를 입력했을때 입력한 값보다 무작위 값이 높으면 'Up' 낮으면 'Down'이라고 나옵니다");
		System.out.println("그럼 좋은 시간 되시기를 바라겠습니다.");

		Scanner sc = new Scanner(System.in);

		double randomValue = Math.random();
		int intValue = (int) (randomValue * 100 + 1);// *100은 최댓값을 100으로 설정

		System.out.printf("숫자를 입력하세요:");
		int number = sc.nextInt();

		while (number != intValue) {

			if (number < intValue)
				System.out.println("Up!");// 입력된 값보다 무작위 변수가 클때
			else
				System.out.println("Down!");

			System.out.printf("숫자를 입력하세요:");
			number = sc.nextInt();

		}

		System.out.println("맞습니다. 숫자는 " + intValue + "입니다.");
		sc.close();
	}

}
