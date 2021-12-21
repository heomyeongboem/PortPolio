package practice;

import java.util.Scanner;

interface Showable {
	void show(String s);
}

interface Pickable {
	char pick(String s1, int i);
}

interface Operable {
	int operator(int x, int y);
}

interface Newable {
	String getString(String s);
}

interface IntArray {
	int[] getArray(int size);
}

class Utils {

	int add(int a, int b) {
		return a + b;
	}
}

public class practice03 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);

		// Showable구현
		System.out.printf("고대로 출력하고 싶은 문자열을 적으시오>>");
		String m_s = sc.nextLine();// nextLine()은 공백 상관없이 엔터 칠 때까지 입력받음
		Showable m_Showable = (s) -> System.out.println(s);
		m_Showable.show(m_s);

		// operable 구현 및 Utils를 이용한다는게 implements관계인지 클래스안에 interface를 선언하는지는 모르겠지만 그건
		// 아닌 것 같아서 이렇게 적어봤습니다.
		System.out.printf("더하기 연산을 할 숫자 두개를 입력하시오>>");
		int m_x = sc.nextInt();
		int m_y = sc.nextInt();
		Operable m_Operable = (x, y) -> {

			Utils m_Utils = new Utils();
			return m_Utils.add(x, y);
		};
		System.out.println(m_Operable.operator(m_x, m_y));

		// Pickable 구현
		System.out.printf("문자열과 몇번째 인덱스를 가져올지 적으시오>>");
		String m_s1 = sc.next();// next()는 공백있으면 거기까지 저장
		int m_i = sc.nextInt();
		Pickable m_Pickable = (s1, i) -> {
			return s1.charAt(i); // charAt(i): 문자열중 i번째 인덱스 위치에 있는 배열을 반환
			// 2를 입력하여 세번째의 글짜가 나온다는것은 프로그래밍상 배열의 인덱스와 똑같은 구조라 i-1해줄 필요없이 i로 적어주면 됌
		};
		System.out.println(m_Pickable.pick(m_s1, m_i));

		// Newable 구현
		// System.out.printf("문자열을 입력하시오>>");

		Newable m_Newable = (s) -> {

			String N_s = new String("사과");
			return N_s;
		};
		System.out.println(m_Newable.getString(m_s));

		// IntArray
		System.out.printf("생성할 배열의 갯수를 입력하시오>>");
		int m_size = sc.nextInt();
		IntArray m_IntArray = (size) -> {
			int[] A = new int[size];
			for (int i = 0; i < size; i++) {
				A[i] = 0;
			}
			return A;
		};

		int[] m_A = m_IntArray.getArray(m_size);

		for (int i = 0; i < m_size; i++) {
			System.out.println(m_A[i]);
		}

		sc.close();
	}
}
