package practice;

public class practice02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// ���� ���� Ŭ���� �� main�ʵ� �ȿ� ����
		Bird b = new Bird() {
			void move() {
				System.out.println("�������� ����.~~~~");
			}

			void sound() {
				System.out.println("�۴��۴�~~~~~.");
			}
		}; // ���� Ŭ���� ������ �������� �����ݷ� ������ �����߉� ������ ���� ��

		b.move();

	}

}
