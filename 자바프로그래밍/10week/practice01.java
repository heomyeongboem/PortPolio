package practice;

class Bird {
	void move() {
		System.out.println("새가 움직인다~~~~.");
	}

	void sound() {
		System.out.println("퍼덕퍼덕~~~~~.");
	}
}

public class practice01 {
	// 무명 멤버 클래스는 main 밖에 선언
	static Bird b = new Bird() {// practice01의 멤버 필드로 아래의 public static void main(String[] args) 안에서 구현을 시킬려면
								// static 필드로 선언을 해주어야됌
		public void move() {
			System.out.println("독수리가 날아가요~~.");
		}

		public void sound() {
			System.out.println("휘리릭~~");
		}
	};

	public static void main(String[] args) {//
		// TODO Auto-generated method stub
		b.move();
		b.sound();

	}

}
