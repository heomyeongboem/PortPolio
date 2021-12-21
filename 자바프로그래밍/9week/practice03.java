package practice;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class practice03 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		m_Stack S = new m_Stack();

		System.out.print("총 스택 저장 공간의 크기 입력 >>");
		S.SetterStackSize(sc.nextInt());

		String str;// 아무리 봐도 do while문안에서 입력을 한번만 받게 짜려면 이방법밖에 없었습니다.

		do {
			System.out.print("문자열 입력>>");
			str = sc.next();

			if (str.equals("stop")) {
				break;
			}

			else if (S.FullStackSize() == S.StackSize()) {// 현재개수가 전체개수와 같으면 종료 (종료조건2)
				System.out.println("스택이 꽉 차서 푸시 불가!");
				// break;// 현재갯수가 고정갯수와 같으면 멈춤}
			} else {
				S.push(str);
				S.SetterStackSize();
			}

		} while (!str.equals("stop")); // stop되면 멈춤 (종료조건1)

		for (int i = 0; i < S.StackSize(); i++) {
			System.out.printf(" %s", S.peek());
		}
		sc.close();
	}

}

interface Stack {

	int StackSize();// 현재 스택에 저장된 개수 리턴 메소드

	int FullStackSize();// 스택의 전체 저장 가능한 개수 리턴

	void push(String a);// 스택의 top에 문자열 저장

	String peek();// 스택의 top에 저장된 문자열 리턴

}

class m_Stack implements Stack {

	List<String> str = new ArrayList<String>();// 동적배열로 할당

	int top = -1;
	int number = 0;// 현재갯수
	int Full;

	// 현재개수를 넣어줌
	public void SetterStackSize() {
		number++;
	}

	// 현재 스택에 저장된 개수 리턴 메소드
	@Override
	public int StackSize() {
		return number;
	}

	// 전체고정갯수 넣어줌
	public void SetterStackSize(int a) {
		this.Full = a;
	}

	// 스택의 전체 저장 가능한 개수 리턴
	@Override
	public int FullStackSize() {
		return Full;
	}

	// 스택의 top에 문자열 저장
	@Override
	public void push(String a) {
		top++;
		str.add(a);// arrayList 객체에 추가해주는 메소드로 동적배열인 ArrayList를 적어줌으로써 top을 기입하지는
	}// 못했지만 peek함수에서 top을 사용할 수 있도록 top++을 해줍니다.

	// 스택의 top에 저장된 문자열 리턴
	@Override
	public String peek() {

		return str.get(top--);// top의 인덱스를 가져옵니다.

	}

}
