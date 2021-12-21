package practice;

import java.util.Scanner;

public class practice1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s;
		Scanner sc = new Scanner(System.in);

		System.out.println("문자열을 입력하세요");
		s = sc.nextLine();// next는 공백이 있으면 더 이상의 입력은 무의미하다!!!
		int count = 0;

		// String을 한글자씩 받아서 갯수를 세는것은 어렵기 때문에 char형으로 문자열 조작을 해준다.
		for (int i = 0; i < s.length(); i++) {

			char c = s.charAt(i);
			if (c >= 'A' && c <= 'Z') {
				count++;
			}
		}
		System.out.println("대문자의 갯수는" + count + "개 입니다");
		sc.close();
	}

}
