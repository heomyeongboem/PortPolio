package practice;

public class practice3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		KoreanExample KE = new KoreanExample();// ��ü ����
		KE.MethodPrint();// �Լ���
	}

}

class Korean {

	String nation = "���ѹα�";
	String name;
	String id;

	public Korean(String n, String s) {// ����Ʈ ������ ��� �����ڰ� ���� ����
		// �����ڰ� ������ ������ ���� �� �����Ϸ��� �⺻ ������ �߰����� ����
		// new �����ڷ� ��ü ������ �����ڰ� ������ ������ �ݵ�� ���
		this.name = n;// this�� ��� �ʵ带 ����ϱ� ���� ���
		this.id = s;
	}

}

class KoreanExample {

	Korean k1 = new Korean("����", "011225-1234567");// ��ü �����Ҷ����� ���� ȣ���� �ٷ� �Ǵ��� ó�� �˾ҽ��ϴ�.
	Korean k2 = new Korean("����", "930525-0654321");

	void MethodPrint() {
		System.out.println("k1.name :" + k1.name);
		System.out.println("k1.id :" + k1.id);
		System.out.println("k2.name :" + k2.name);
		System.out.println("k2.id :" + k2.id);
	}
}
