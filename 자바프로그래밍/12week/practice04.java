package practice;

import java.util.HashMap;
import java.util.Scanner;

public class practice04 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		HashMap<String, String> dic = new HashMap<String, String>(); // HashMap ���� ���� : Key,Value ���� ���� ���� �ֱ� ���ؼ�
		dic.put("baby", "�Ʊ�");// put: Key,Value ���� ���� ���� �־��ִ� HashMap�� �޼ҵ�
		dic.put("love", "���");
		dic.put("apple", "���");

		Scanner sc = new Scanner(System.in);
		while (true) {
			System.out.print("ã�� ���� �ܾ��(����ܾ �����մϴ� ����)?");
			String eng = sc.next();// key���� ����ܾ �Է¹���
			if (eng.equals("exit"))// �Է� ���� �ܾ exit�� ������ ����
			{
				System.out.println("�����մϴ�...");
				break;
			}
			String Kor = dic.get(eng);// HashMap.get=Returns the value to which the specified key is mapped
			if (Kor == null)
				System.out.println(eng + "�� ���� �ܾ� �Դϴ�.");// ���� ���� �ܾ�(key)ġ�� null�� ��ȯ�ϱ� ������ ����
			else
				System.out.println(Kor);// ������ ���
		}
		sc.close();
	}

}
