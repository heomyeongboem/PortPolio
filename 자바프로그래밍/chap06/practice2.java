package practice;

import java.util.Scanner;

public class practice2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		CarTest CT = new CarTest();
		CT.Function();
	}

}

class Car {
	String company;
	String model;
	String color;

	static int numOfCars = 0;
	static int numOfRedCars = 0;

	public Car(String a, String b, String c)// field의 모든 값을 매개변수로 전달받아 field 값 초기화
	{
		this.company = a;
		this.model = b;
		this.color = c;
		numOfCars++;

		if (color.equalsIgnoreCase("red"))// color에 대문자 소문자 상관없이 red나오면 1을 반환
			numOfRedCars++;
	}
}

class CarTest {

	void Function() {

		Scanner sc = new Scanner(System.in);

		System.out.println("3개의 차량에 대한 정보를 입력 할 것입니다.");
		System.out.println("제조사 모델명 색상 순으로 입력해주시길 간곡히 바라겠습니다.");

		System.out.printf("첫번째 차량 정보 기입\n");
		String m_company = sc.next();
		String m_model = sc.next();
		String m_color = sc.next();
		Car C1 = new Car(m_company, m_model, m_color);

		System.out.printf("두번째 차량 정보 기입\n");
		m_company = sc.next();
		m_model = sc.next();
		m_color = sc.next();
		Car C2 = new Car(m_company, m_model, m_color);

		System.out.printf("세번째 차량 정보 기입\n");
		m_company = sc.next();
		m_model = sc.next();
		m_color = sc.next();
		Car C3 = new Car(m_company, m_model, m_color);

		System.out.printf("자동차의 갯수:%d, 빨간색 자동차의 갯수:%d\n", Car.numOfCars, Car.numOfRedCars);
		sc.close();

	}

}
