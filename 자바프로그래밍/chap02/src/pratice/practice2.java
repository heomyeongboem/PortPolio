package pratice;

import java.util.Scanner;

public class practice2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int x;
		int y;
		Scanner sc = new Scanner(System.in);
		System.out.printf("Simple Calculator");
		System.out.printf("Enter the first number:");
		x = sc.nextInt();
		System.out.printf("Enter the second number:");
		y = sc.nextInt();
		System.out.printf("x+y=%d\n", x + y);
		System.out.printf("x-y=%d\n", x - y);
		System.out.printf("x*y=%d\n", x * y);
		System.out.printf("x/y=%d\n", x / y);
		System.out.println("x%y=" + x % y);// 얘는 printf시 error 가 나서 println으로 작성하였습니다.!!!
		sc.close();
	}

}
