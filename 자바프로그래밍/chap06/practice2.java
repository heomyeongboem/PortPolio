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

	public Car(String a, String b, String c)// field�� ��� ���� �Ű������� ���޹޾� field �� �ʱ�ȭ
	{
		this.company = a;
		this.model = b;
		this.color = c;
		numOfCars++;

		if (color.equalsIgnoreCase("red"))// color�� �빮�� �ҹ��� ������� red������ 1�� ��ȯ
			numOfRedCars++;
	}
}

class CarTest {

	void Function() {

		Scanner sc = new Scanner(System.in);

		System.out.println("3���� ������ ���� ������ �Է� �� ���Դϴ�.");
		System.out.println("������ �𵨸� ���� ������ �Է����ֽñ� ������ �ٶ�ڽ��ϴ�.");

		System.out.printf("ù��° ���� ���� ����\n");
		String m_company = sc.next();
		String m_model = sc.next();
		String m_color = sc.next();
		Car C1 = new Car(m_company, m_model, m_color);

		System.out.printf("�ι�° ���� ���� ����\n");
		m_company = sc.next();
		m_model = sc.next();
		m_color = sc.next();
		Car C2 = new Car(m_company, m_model, m_color);

		System.out.printf("����° ���� ���� ����\n");
		m_company = sc.next();
		m_model = sc.next();
		m_color = sc.next();
		Car C3 = new Car(m_company, m_model, m_color);

		System.out.printf("�ڵ����� ����:%d, ������ �ڵ����� ����:%d\n", Car.numOfCars, Car.numOfRedCars);
		sc.close();

	}

}
