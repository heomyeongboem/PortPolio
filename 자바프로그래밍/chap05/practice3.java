package practice;

public class practice3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		KoreanExample KE = new KoreanExample();// 객체 생성
		KE.MethodPrint();// 함수명
	}

}

class Korean {

	String nation = "대한민국";
	String name;
	String id;

	public Korean(String n, String s) {// 디폴트 생성자 대신 개발자가 직접 선언
		// 개발자가 선언한 생성자 존재 시 컴파일러는 기본 생성자 추가하지 않음
		// new 연산자로 객체 생성시 개발자가 선언한 생성자 반드시 사용
		this.name = n;// this는 멤버 필드를 사용하기 위해 사용
		this.id = s;
	}

}

class KoreanExample {

	Korean k1 = new Korean("연세", "011225-1234567");// 객체 생성할때부터 힘수 호출이 바로 되는지 처음 알았습니다.
	Korean k2 = new Korean("믿음", "930525-0654321");

	void MethodPrint() {
		System.out.println("k1.name :" + k1.name);
		System.out.println("k1.id :" + k1.id);
		System.out.println("k2.name :" + k2.name);
		System.out.println("k2.id :" + k2.id);
	}
}
