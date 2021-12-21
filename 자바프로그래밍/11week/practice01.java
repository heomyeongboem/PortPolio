package practice;

import java.util.Scanner;

@SuppressWarnings("serial")
class TimeInUseException extends Exception {

	public String getMessage() {

		return "선택한 시간은 이미 예약됨";
	}

}

@SuppressWarnings("serial")
class InvalidTimeException extends Exception {

	public String getMessage() {

		return "선택한 시간이 범위 밖에 있음";
	}

}

class Student {
	int Student_ID;
	String Name;

	Student(int Student_ID, String Name) // 매개변수를 갖는 생성자
	{
		this.Student_ID = Student_ID;
		this.Name = Name;
	}

	int return_Student_ID()// 학번 반환
	{
		return this.Student_ID;
	}

	String return_name() // 이름 반환
	{
		return this.Name;
	}
}

class TimeScheduler {

	Student[] student = new Student[6];// Student객체 배열 생성

	// TimeInUseException, InvalidTimeException예외 처리 수정하면 끝
	void reservation() throws InvalidTimeException, TimeInUseException {

		Scanner sc = new Scanner(System.in);
		int i = 0;// 종료조건
		// while (student != null)
		// 내가 봤을때 문제점은 for문이다. 6개를 다 채워야만 끝내게 만들어야된다. 그러므로 for 문 말고 while문으로 대체해야된다.
		// 밥먹으러간다.밥 안먹었다.
		while (i < 6) {
			try {
				System.out.printf("학생의 학번을 입력하세요: ");
				int I_Student_ID = sc.nextInt();

				System.out.printf("학생의 이름을 입력하세요: ");
				String I_Name = sc.next();

				Student m_student = new Student(I_Student_ID, I_Name);// 힉생 객체 생성

				System.out.printf("원하는 상담시간(1, 2, 3, 4, 5, 6 중 선택):");

				int Time = sc.nextInt();
				if (Time - 1 > student.length)// 예외타입 InvalidTimeException
					throw new InvalidTimeException();
				if (student[Time - 1] != null)// 예외타입 TimeInUseException
					throw new TimeInUseException();
				student[Time - 1] = m_student;
				i++;// 이 문이 성립한다는것은 객체에 값이 들어왔다는 것을 의미
			} catch (InvalidTimeException e) {
				System.out.println(e.getMessage());
			} catch (TimeInUseException e) {
				System.out.println(e.getMessage());
			}
		}
		sc.close();
	}

	void print() {
		System.out.println("상담 시간 예약 목록");
		System.out.println();
		System.out.println("상담시간  학번   이름");
		for (int i = 0; i < student.length; i++) {
			int m_Student_ID = student[i].return_Student_ID();// 반환출력
			String m_Name = student[i].return_name();// 반환출력
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
