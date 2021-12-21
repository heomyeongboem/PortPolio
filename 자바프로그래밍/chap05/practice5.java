package practice;

import java.util.Scanner;

public class practice5 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		TestTV hard = new TestTV();// 객체 생성
		hard.TV1();
	}
}

class TV {// 클래스 생성

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
			System.out.println("전원이 이미 켜져있습니다.");
		else {
			on = true;
			System.out.println("전원을 킵니다.");
		}
	}

	void turnOff() {// 2
		if (on == false)
			System.out.println("전원이 이미 꺼져있습니다.");
		else {
			on = false;
			System.out.println("전원을 끕니다.");
		}
	}

	void setChannel(int newChannel) {// 3

		if (newChannel > 120 || newChannel < 1)
			System.out.println("없는 채널입니다. 다시 확인해주시길 바랍니다.");
		else {
			channel = newChannel;
			System.out.printf("현재 채널: %d\n", newChannel);
		}

	}

	void setVolume(int newVolumeLevel) {// 4

		if (newVolumeLevel > 7 || newVolumeLevel < 1)
			System.out.println("없는 음량입니다.");
		else {
			volume = newVolumeLevel;
			System.out.printf("현재 음량: %d\n", volume);
		}
	}

	void channelUp() {// 5

		if (channel == 120)
			System.out.println("멈추십쇼");
		else {
			channel++;
		}
	}

	void channelDown() {// 6

		if (channel == 1)
			System.out.println("멈추십쇼");
		else {
			channel--;
		}
	}

	void volumeUp() {// 7

		if (volume == 7)
			System.out.println("멈추십쇼");
		else {
			volume++;
		}
	}

	void volumeDown() {// 8

		if (volume == 1)
			System.out.println("멈추십쇼");
		else {
			volume--;
		}
	}
}

class TestTV {// 클래스 생성

	void TV1() {

		TV HMBC = new TV();// TV 객체 HMBC 생성
		Scanner sc = new Scanner(System.in);

		int exit = 1;

		while (exit == 1) {
			System.out.println(
					"1.turnOn 2.turnOff 3.setChannel 4.setVolume 5.channelUp 6.channelDown 7.volumeUp 8.volumeDown 9.exit");
			System.out.printf("원하시는 번호를 입력해주세요:");
			int function = sc.nextInt(); // 무슨 기능을 작동할지 정해주는 변수
			switch (function) {

			case 1: // TV켜기
				HMBC.turnOn();
				break;

			case 2: // TV끄기
				HMBC.turnOff();
				break;

			case 3:
				System.out.println(
						"1번 부터 120번 채널까지 있으며,1~11까지는 정규방송,11~30까지는 비정규방송,30~40까지는 예능방송,40~50까지는 문화방송 50~60까지는 영화");
				System.out.println("60~70까지는 교육방송, 70~100까지는 KIDS방송, 100~120까지는 19금 방송입니다.");
				System.out.printf("원하시는 채널을 입력해주세요:");
				int number = sc.nextInt();
				HMBC.setChannel(number);
				break;

			case 4:
				System.out.printf("원하시는 음량을 입력해주세요(1~7):");
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
