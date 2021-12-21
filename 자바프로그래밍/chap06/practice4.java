package practice;

public class practice4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}

class Circle {
	private void secret() {// 얘는 private이기 때문에 절대 사용 못하는 함수
		System.out.println("비밀이다.");
	}

	protected void findRadius() {// 얘는 protected이기 때문에 상속받은 클래스에서 사용가능

		System.out.println("반지름이 10.0센티이다.");
	}

	public void findArea() {// 얘는 public이기 때문에 상속받은 클래스에서 사용가능
		System.out.println("넓이는 (3.14*반지름*반지름)이다.");
	}
}

class Ball extends Circle {

	private String color;

	public Ball(String color) {// 객체 생성자로 객체 생성시 입력을 받아 멤버함수인 color에 저장가능
		this.color = color;
	}

	public void findColor() {// 출력해주는 함수
		System.out.println(color + "공이다.");
	}

	public void findVolumn() {// 출력해주는 함수
		System.out.println("부피는 4/3*(3.14*반지름*반지름*반지름)이다.");
	}
}

class InheritanceDemo {

	public static void main(String[] args) {

		Circle c1 = new Circle();// Circle 클래스 객체 c1 생성
		Ball c2 = new Ball("빨간색");// Ball 클래스 객체 c2 생성
		System.out.println("원 :");// 출력
		c1.findRadius();// Circle 클래스의 findRadius() 함수 사용
		c1.findArea();// Circle 클래스의 findArea() 함수 사용
		System.out.println("\n공 :");// 출력
		c2.findRadius();// Circle 클래스의 findRadius() 함수를 Circle 클래스를 상속받은 Ball 클래스에서 사용
		c2.findArea();// Circle 클래스의 findArea() 함수를 Circle 클래스를 상속받은 Ball 클래스에서 사용
		c2.findColor();// Circle 클래스의 findColor() 함수를 Circle 클래스를 상속받은 Ball 클래스에서 사용
		c2.findVolumn();// Circle 클래스의 findVolumn() 함수를 Circle 클래스를 상속받은 Ball 클래스에서 사용
	}
}
