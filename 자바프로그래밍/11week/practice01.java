package practice;

import java.util.Scanner;

@SuppressWarnings("serial")
class TimeInUseException extends Exception {

	public String getMessage() {

		return "������ �ð��� �̹� �����";
	}

}

@SuppressWarnings("serial")
class InvalidTimeException extends Exception {

	public String getMessage() {

		return "������ �ð��� ���� �ۿ� ����";
	}

}

class Student {
	int Student_ID;
	String Name;

	Student(int Student_ID, String Name) // �Ű������� ���� ������
	{
		this.Student_ID = Student_ID;
		this.Name = Name;
	}

	int return_Student_ID()// �й� ��ȯ
	{
		return this.Student_ID;
	}

	String return_name() // �̸� ��ȯ
	{
		return this.Name;
	}
}

class TimeScheduler {

	Student[] student = new Student[6];// Student��ü �迭 ����

	// TimeInUseException, InvalidTimeException���� ó�� �����ϸ� ��
	void reservation() throws InvalidTimeException, TimeInUseException {

		Scanner sc = new Scanner(System.in);
		int i = 0;// ��������
		// while (student != null)
		// ���� ������ �������� for���̴�. 6���� �� ä���߸� ������ �����ߵȴ�. �׷��Ƿ� for �� ���� while������ ��ü�ؾߵȴ�.
		// �����������.�� �ȸԾ���.
		while (i < 6) {
			try {
				System.out.printf("�л��� �й��� �Է��ϼ���: ");
				int I_Student_ID = sc.nextInt();

				System.out.printf("�л��� �̸��� �Է��ϼ���: ");
				String I_Name = sc.next();

				Student m_student = new Student(I_Student_ID, I_Name);// ���� ��ü ����

				System.out.printf("���ϴ� ���ð�(1, 2, 3, 4, 5, 6 �� ����):");

				int Time = sc.nextInt();
				if (Time - 1 > student.length)// ����Ÿ�� InvalidTimeException
					throw new InvalidTimeException();
				if (student[Time - 1] != null)// ����Ÿ�� TimeInUseException
					throw new TimeInUseException();
				student[Time - 1] = m_student;
				i++;// �� ���� �����Ѵٴ°��� ��ü�� ���� ���Դٴ� ���� �ǹ�
			} catch (InvalidTimeException e) {
				System.out.println(e.getMessage());
			} catch (TimeInUseException e) {
				System.out.println(e.getMessage());
			}
		}
		sc.close();
	}

	void print() {
		System.out.println("��� �ð� ���� ���");
		System.out.println();
		System.out.println("���ð�  �й�   �̸�");
		for (int i = 0; i < student.length; i++) {
			int m_Student_ID = student[i].return_Student_ID();// ��ȯ���
			String m_Name = student[i].return_name();// ��ȯ���
			int m = i + 1;

			System.out.println("  " + m + "     " + m_Student_ID + "   " + m_Name);
		}
	}
}

public class practice01 {

	public static void main(String[] args) throws InvalidTimeException, TimeInUseException {
		// TODO Auto-generated method stub

		TimeScheduler TS = new TimeScheduler();
		TS.reservation();
		TS.print();

	}

}
