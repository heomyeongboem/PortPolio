package practice;

class Bird {
	void move() {
		System.out.println("���� �����δ�~~~~.");
	}

	void sound() {
		System.out.println("�۴��۴�~~~~~.");
	}
}

public class practice01 {
	// ���� ��� Ŭ������ main �ۿ� ����
	static Bird b = new Bird() {// practice01�� ��� �ʵ�� �Ʒ��� public static void main(String[] args) �ȿ��� ������ ��ų����
								// static �ʵ�� ������ ���־�߉�
		public void move() {
			System.out.println("�������� ���ư���~~.");
		}

		public void sound() {
			System.out.println("�ָ���~~");
		}
	};

	public static void main(String[] args) {//
		// TODO Auto-generated method stub
		b.move();
		b.sound();

	}

}
