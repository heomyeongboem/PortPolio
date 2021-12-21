package practice;

import java.util.Scanner;

public class practice3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		char operator;
		int num_1, num_2;

		Scanner sc = new Scanner(System.in);

		System.out.println("원하시는 연산을 입력하세요:");
		operator = sc.next().charAt(0);// next함수에서는 char를 받을 수 없기 때문에 charAt(0)을 추가로 적어줬습니다. (검색 해본결과)

		System.out.println("원하시는 정수 두개를 입력하세요:");
		num_1 = sc.nextInt();
		num_2 = sc.nextInt();

		switch (operator) {

		case '+':
			System.out.printf("%d+%d=%d", num_1, num_2, num_1 + num_2);
			break;

		case '-':
			System.out.printf("%d-%d=%d", num_1, num_2, num_1 - num_2);
			break;

		case '*':
			System.out.printf("%d*%d=%d", num_1, num_2, num_1 * num_2);
			break;

		case '/':
			System.out.printf("%d/%d=%d", num_1, num_2, num_1 / num_2);
			break;

		case '%':
			System.out.println(+num_1 + "%" + num_2 + "=" + (num_1 % num_2));
			break;

		default:

			System.out.printf("Wrong input");

		}

		sc.close();
	}

}
