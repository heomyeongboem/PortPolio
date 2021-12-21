package practice;

import java.util.ArrayList;
import java.util.Scanner;

public class practice01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<String> a = new ArrayList<String>();

		Scanner sc = new Scanner(System.in);
		// 값 넣기
		for (int i = 0; i < 4; i++) {
			System.out.print("이름을 입력하세요>>");
			String s = sc.next();
			a.add(s);// ArrayList<String> a 에 값 s 넣기
		}
		// 값 출력
		for (int i = 0; i < a.size(); i++) {
			String name = a.get(i); // ArrayList에 i번째 문자열 얻어오기
			System.out.print(name + " ");
		}
		sc.close();
	}

}
