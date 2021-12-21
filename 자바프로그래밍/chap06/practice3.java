package practice;

import java.util.Scanner;

public class practice3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BMITest BT = new BMITest();
		BT.test();
	}

}

class BMI {

	private String name;
	private int age;
	private double weight;
	private double height;

	public BMI(String a, int b, double c, double d) {
		this.name = a;
		this.age = b;
		this.weight = c;
		this.height = d;
	}

	public double Getter1() {
		return weight / (height * height); // 몸무게를 키의 제곱으로 나눔하여 소수점 아래 1자리까지
	}// BMI 계산

	public String Getter2() {
		if (Getter1() < 18.5)
			return "Underweight";
		else if (Getter1() < 25.0)
			return "Normal";
		else if (Getter1() < 30.0)
			return "Overweight";
		else
			return "Normal";
	}

	public String Getter3() {
		return name;
	}

	public void Setter1(int m_weight) {
		weight = m_weight;
	}

	public void Setter2(int m_height) {
		height = m_height;
	}

}

class BMITest {

	void test() {

		Scanner sc = new Scanner(System.in);

		String T_name;
		int T_age;
		double T_weight;
		double T_height;

		System.out.println("36번 훈련병 이름, 나이, 체중, 키 순으로 입력해주시길 바라겠습니다.");
		T_name = sc.next();
		T_age = sc.nextInt();
		T_weight = sc.nextFloat();
		T_height = sc.nextFloat();

		BMI bmi1 = new BMI(T_name, T_age, T_weight, T_height);

		System.out.println("37번 훈련병 이름, 나이, 체중, 키 순으로 입력해주시길 바라겠습니다.");
		T_name = sc.next();
		T_age = sc.nextInt();
		T_weight = sc.nextFloat();
		T_height = sc.nextFloat();
		BMI bmi2 = new BMI(T_name, T_age, T_weight, T_height);

		System.out.printf("이름:%s, BMI 지수:%f 상태:%s", bmi1.Getter3(), bmi1.Getter1(), bmi1.Getter2());
		System.out.println();
		System.out.printf("이름:%s, BMI 지수:%f 상태:%s", bmi2.Getter3(), bmi2.Getter1(), bmi2.Getter2());

		sc.close();
	}

}
