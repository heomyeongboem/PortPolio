package practice;

import java.util.Scanner;

public class practice5 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		TestTV hard = new TestTV();// ��ü ����
		hard.TV1();
	}
}

class TV {// Ŭ���� ����

	int channel;
	int volume;
	boolean on;

	public TV() {

		channel = 1;
		volume = 1;
		on = false;
	}

	void turnOn() {// 1
		if (on == true)
			System.out.println("������ �̹� �����ֽ��ϴ�.");
		else {
			on = true;
			System.out.println("������ ŵ�ϴ�.");
		}
	}

	void turnOff() {// 2
		if (on == false)
			System.out.println("������ �̹� �����ֽ��ϴ�.");
		else {
			on = false;
			System.out.println("������ ���ϴ�.");
		}
	}

	void setChannel(int newChannel) {// 3

		if (newChannel > 120 || newChannel < 1)
			System.out.println("���� ä���Դϴ�. �ٽ� Ȯ�����ֽñ� �ٶ��ϴ�.");
		else {
			channel = newChannel;
			System.out.printf("���� ä��: %d\n", newChannel);
		}

	}

	void setVolume(int newVolumeLevel) {// 4

		if (newVolumeLevel > 7 || newVolumeLevel < 1)
			System.out.println("���� �����Դϴ�.");
		else {
			volume = newVolumeLevel;
			System.out.printf("���� ����: %d\n", volume);
		}
	}

	void channelUp() {// 5

		if (channel == 120)
			System.out.println("���߽ʼ�");
		else {
			channel++;
		}
	}

	void channelDown() {// 6

		if (channel == 1)
			System.out.println("���߽ʼ�");
		else {
			channel--;
		}
	}

	void volumeUp() {// 7

		if (volume == 7)
			System.out.println("���߽ʼ�");
		else {
			volume++;
		}
	}

	void volumeDown() {// 8

		if (volume == 1)
			System.out.println("���߽ʼ�");
		else {
			volume--;
		}
	}
}

class TestTV {// Ŭ���� ����

	void TV1() {

		TV HMBC = new TV();// TV ��ü HMBC ����
		Scanner sc = new Scanner(System.in);

		int exit = 1;

		while (exit == 1) {
			System.out.println(
					"1.turnOn 2.turnOff 3.setChannel 4.setVolume 5.channelUp 6.channelDown 7.volumeUp 8.volumeDown 9.exit");
			System.out.printf("���Ͻô� ��ȣ�� �Է����ּ���:");
			int function = sc.nextInt(); // ���� ����� �۵����� �����ִ� ����
			switch (function) {

			case 1: // TV�ѱ�
				HMBC.turnOn();
				break;

			case 2: // TV����
				HMBC.turnOff();
				break;

			case 3:
				System.out.println(
						"1�� ���� 120�� ä�α��� ������,1~11������ ���Թ��,11~30������ �����Թ��,30~40������ ���ɹ��,40~50������ ��ȭ��� 50~60������ ��ȭ");
				System.out.println("60~70������ �������, 70~100������ KIDS���, 100~120������ 19�� ����Դϴ�.");
				System.out.printf("���Ͻô� ä���� �Է����ּ���:");
				int number = sc.nextInt();
				HMBC.setChannel(number);
				break;

			case 4:
				System.out.printf("���Ͻô� ������ �Է����ּ���(1~7):");
				int m_volume = sc.nextInt();
				HMBC.setVolume(m_volume);
				break;

			case 5:
				HMBC.channelUp();
				break;

			case 6:
				HMBC.channelDown();
				break;

			case 7:
				HMBC.volumeUp();
				break;

			case 8:
				HMBC.volumeDown();
				break;

			case 9:
				exit = 0;
				break;
			}

		}

		System.out.printf("channel: %d\n", HMBC.channel);
		System.out.printf("volumeLevel: %d\n", HMBC.volume);
		System.out.printf("on: %s\n", HMBC.on);
		sc.close();
	}

}
