package practice;

public class practice4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}

class Circle {
	private void secret() {// ��� private�̱� ������ ���� ��� ���ϴ� �Լ�
		System.out.println("����̴�.");
	}

	protected void findRadius() {// ��� protected�̱� ������ ��ӹ��� Ŭ�������� ��밡��

		System.out.println("�������� 10.0��Ƽ�̴�.");
	}

	public void findArea() {// ��� public�̱� ������ ��ӹ��� Ŭ�������� ��밡��
		System.out.println("���̴� (3.14*������*������)�̴�.");
	}
}

class Ball extends Circle {

	private String color;

	public Ball(String color) {// ��ü �����ڷ� ��ü ������ �Է��� �޾� ����Լ��� color�� ���尡��
		this.color = color;
	}

	public void findColor() {// ������ִ� �Լ�
		System.out.println(color + "���̴�.");
	}

	public void findVolumn() {// ������ִ� �Լ�
		System.out.println("���Ǵ� 4/3*(3.14*������*������*������)�̴�.");
	}
}

class InheritanceDemo {

	public static void main(String[] args) {

		Circle c1 = new Circle();// Circle Ŭ���� ��ü c1 ����
		Ball c2 = new Ball("������");// Ball Ŭ���� ��ü c2 ����
		System.out.println("�� :");// ���
		c1.findRadius();// Circle Ŭ������ findRadius() �Լ� ���
		c1.findArea();// Circle Ŭ������ findArea() �Լ� ���
		System.out.println("\n�� :");// ���
		c2.findRadius();// Circle Ŭ������ findRadius() �Լ��� Circle Ŭ������ ��ӹ��� Ball Ŭ�������� ���
		c2.findArea();// Circle Ŭ������ findArea() �Լ��� Circle Ŭ������ ��ӹ��� Ball Ŭ�������� ���
		c2.findColor();// Circle Ŭ������ findColor() �Լ��� Circle Ŭ������ ��ӹ��� Ball Ŭ�������� ���
		c2.findVolumn();// Circle Ŭ������ findVolumn() �Լ��� Circle Ŭ������ ��ӹ��� Ball Ŭ�������� ���
	}
}
