package practice;

public class practice4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		TestCircle TC = new TestCircle();// 객체 생성

		TC.K1();

		TC.K2();

		TC.K3();

		TC.k4();

	}

}

class Circle {// Circle 객체 생성

	double radius;

	public Circle() // Constructor1
	{
		radius = 1;
	}

	public Circle(double k) // Constructor2
	{
		this.radius = k;
	}

	void setRadius(double m) // radius값을 수정
	{
		this.radius = m;
	}

	double getArea() {
		return 3.14 * radius * radius;// 3.14*(r^2)
	}

	double getCircuference() {
		return 2 * 3.14 * radius; // 2*3.14*r
	}

}

class TestCircle {

	Circle C1 = new Circle();// Circle 객체 생성
	Circle C2 = new Circle(25);// Circle 객체 생성 25로 필드값 초기화
	Circle C3 = new Circle(125);// Circle 객체 생성 125로 필드값 초기화

	void K1() {

		System.out.println(
				"circle1: 원의 반지름이 " + C1.radius + "일때, 넓이는 " + C1.getArea() + ", 둘레는 " + C1.getCircuference() + "입니다.");

	}

	void K2() {

		System.out.println(
				"circle2: 원의 반지름이 " + C2.radius + "일때, 넓이는 " + C2.getArea() + ", 둘레는 " + C2.getCircuference() + "입니다.");

	}

	void K3() {

		System.out.println(
				"circle3: 원의 반지름이 " + C3.radius + "일때, 넓이는 " + C3.getArea() + ", 둘레는 " + C3.getCircuference() + "입니다.");
	}

	void k4() {
		System.out.println();
		System.out.println("circle1의 반지름을 100으로 수정한 후:");
		C1.setRadius(100);
		System.out.println(
				"circle1: 원의 반지름이 " + C1.radius + "일때, 넓이는 " + C1.getArea() + ", 둘레는 " + C1.getCircuference() + "입니다.");
	}

}