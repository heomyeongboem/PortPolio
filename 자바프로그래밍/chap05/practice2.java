package practice;

public class practice2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		CarExample CE = new CarExample();// 객체 생성
		CE.Print();// 출력함수
	}

}

class Car {
	String company = "현대자동차";
	String model = "그랜져";
	String color = "검정";
	int maxSpeed = 350;
	int speed;

	Car() {
		speed = 0;
	}

}

class CarExample {

	Car myCar = new Car();

	void Print() {

		System.out.println("제작회사: " + myCar.company);
		System.out.println("모델명: " + myCar.model);
		System.out.println("색깔: " + myCar.color);
		System.out.println("최고 속도: " + myCar.maxSpeed);
		System.out.println("현재 속도: " + myCar.speed);

		changeSpeed();
		System.out.println("수정된 속도: " + myCar.speed);
	}

	void changeSpeed() {

		myCar.speed = 60;

	}
}
