package practice;

import java.util.Scanner;

public class practice01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		WonToDollar WTD = new WonToDollar();
		WTD.run();
	}

}

abstract class Converter {

	abstract protected double convert(double src);

	abstract protected String srcString();

	abstract protected String destString();

	protected double ratio;

	public void run() {

		Scanner scanner = new Scanner(System.in);
		System.out.println(srcString() + "��" + destString() + "�� �ٲ�");
		System.out.print(srcString() + "�� �Է��ϼ���>> ");
		double val = scanner.nextDouble();
		double res = convert(val);
		System.out.println("��ȯ���: " + res + destString());
		scanner.close();
	}
}

class WonToDollar extends Converter {

	double cost;

	@Override
	protected double convert(double src) {
		// TODO Auto-generated method stub
		this.cost = src / 1100.0;

		return cost;
	}

	@Override
	protected String srcString() {
		// TODO Auto-generated method stub
		return "��";
	}

	@Override
	protected String destString() {
		// TODO Auto-generated method stub
		return "�޷�";
	}

}
