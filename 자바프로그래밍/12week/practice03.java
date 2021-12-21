package practice;

import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;

public class practice03 {

	static void printList(LinkedList<String> l) {
		Iterator<String> iterator = l.iterator();// �ݺ��� ������ ���Ϸ��� �� iterator
		while (iterator.hasNext()) // LinkedList�� �����ϸ� ���� ���������� �ݺ�
		{
			String e = iterator.next();
			String separator;
			if (iterator.hasNext())
				separator = "->";
			else
				separator = "\n";
			System.out.print(e + separator);
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		LinkedList<String> myList = new LinkedList<String>();
		myList.add("Ʈ��������");
		myList.add("��Ÿ����");
		myList.add("��Ʈ����");
		myList.add(0, "�͹̳�����");
		myList.add(2, "�ƹ�Ÿ");

		Collections.sort(myList); // ������ ������� ����
		printList(myList);

		Collections.reverse(myList); // ����� ������ �ݴ�� ����
		printList(myList);

		int index = Collections.binarySearch(myList, "�ƹ�Ÿ") + 1;// ���̳ʸ� ��ġ
		System.out.println("�ƹ�Ÿ�� " + index + "��° ����Դϴ�.");
	}

}
