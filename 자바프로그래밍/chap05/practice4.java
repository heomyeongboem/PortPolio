package practice;

public class practice4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		TestCircle TC = new TestCircle();// ��ü ����

		TC.K1();

		TC.K2();

		TC.K3();

		TC.k4();

	}

}

class Circle {// Circle ��ü ����

	double radius;

	public Circle() // Constructor1
	{
		radius = 1;
	}

	public Circle(double k) // Constructor2
	{
		this.radius = k;
	}

	void setRadius(double m) // radius���� ����
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

	Circle C1 = new Circle();// Circle ��ü ����
	Circle C2 = new Circle(25);// Circle ��ü ���� 25�� �ʵ尪 �ʱ�ȭ
	Circle C3 = new Circle(125);// Circle ��ü ���� 125�� �ʵ尪 �ʱ�ȭ

	void K1() {

		System.out.println(
				"circle1: ���� �������� " + C1.radius + "�϶�, ���̴� " + C1.getArea() + ", �ѷ��� " + C1.getCircuference() + "�Դϴ�.");

	}

	void K2() {

		System.out.println(
				"circle2: ���� �������� " + C2.radius + "�϶�, ���̴� " + C2.getArea() + ", �ѷ��� " + C2.getCircuference() + "�Դϴ�.");

	}

	void K3() {

		System.out.println(
				"circle3: ���� �������� " + C3.radius + "�϶�, ���̴� " + C3.getArea() + ", �ѷ��� " + C3.getCircuference() + "�Դϴ�.");
	}

	void k4() {
		System.out.println();
		System.out.println("circle1�� �������� 100���� ������ ��:");
		C1.setRadius(100);
		System.out.println(
				"circle1: ���� �������� " + C1.radius + "�϶�, ���̴� " + C1.getArea() + ", �ѷ��� " + C1.getCircuference() + "�Դϴ�.");
	}

}