package practice;

public class practice2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		CarExample CE = new CarExample();// ��ü ����
		CE.Print();// ����Լ�
	}

}

class Car {
	String company = "�����ڵ���";
	String model = "�׷���";
	String color = "����";
	int maxSpeed = 350;
	int speed;

	Car() {
		speed = 0;
	}

}

class CarExample {

	Car myCar = new Car();

	void Print() {

		System.out.println("����ȸ��: " + myCar.company);
		System.out.println("�𵨸�: " + myCar.model);
		System.out.println("����: " + myCar.color);
		System.out.println("�ְ� �ӵ�: " + myCar.maxSpeed);
		System.out.println("���� �ӵ�: " + myCar.speed);

		changeSpeed();
		System.out.println("������ �ӵ�: " + myCar.speed);
	}

	void changeSpeed() {

		myCar.speed = 60;

	}
}
