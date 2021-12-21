package practice;

public class practice02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// 무명 지역 클래스 는 main필드 안에 선언
		Bird b = new Bird() {
			void move() {
				System.out.println("독수리가 난다.~~~~");
			}

			void sound() {
				System.out.println("퍼덕퍼덕~~~~~.");
			}
		}; // 무명 클래스 쓸때는 마지막에 세미콜론 무조껀 찍어줘야됌 이유는 나도 모름

		b.move();

	}

}
