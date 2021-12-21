package practice;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.TextField;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

class Panel1 extends JPanel {// 제일 위에 열기, 닫기 ,나가기 버튼을 담을 패널을 생성할 클래스
	public Panel1() {
		setBackground(Color.LIGHT_GRAY);
		// setLayout(new FlowLayout());
		add(new JButton("열기"));// 클래스 안에 생성하면 '.add' 연산자 없이 add만 해도 추가가 되나 봅니다.
		add(new JButton("닫기"));// 닫기 버튼 추가
		add(new JButton("나가기"));// 나가기 버튼 추가
	}
}

class Panel2 extends JPanel {
	public Panel2() {
		setLayout(null);
		for (int i = 0; i < 10; i++) {// 10개의
			int x = (int) (Math.random() * 250);// 랜덤 x축을 가지고
			int y = (int) (Math.random() * 250);// 랜덤 y축을 가지는
			JLabel label = new JLabel("$");// $문자 생성
			label.setForeground(Color.red); // $문자의 색깔로 빨간색 지정
			label.setLocation(x, y); // $문자의 위치 지정
			label.setSize(10, 10); // $크기를 10*10 픽셀로 만듦
			label.setOpaque(true); // Opaque값을 true로 미리 설정해 주어야 배경색이 적용된다.
			add(label);// 라벨을 Panel2 패널에 추가
		}
	}
}

class Panel3 extends JPanel {
	public Panel3() {
		setBackground(Color.YELLOW); // 배경 노란색으로 만들기
		add(new JButton("Word Input"));// 버튼 생성및 추가
		add(new TextField(15)); // 15글자까지 받을 수 있는 텍스트 필드 생성 및 추가
	}
}

public class practice03 extends JFrame {

	practice03() {
		setTitle("여러 개의 패널을 가진 프레임");
		setSize(300, 300);// 크기 300*300 픽셀로 지정
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // Frame에 기본적으로 있는 나가기 버튼 만들어줌
		Panel1 p1 = new Panel1();
		Panel2 p2 = new Panel2();
		Panel3 p3 = new Panel3();
		add(p1, BorderLayout.NORTH); // BorderLayout으로 북쪽에 지정
		add(p3, BorderLayout.SOUTH); // BorderLayout으로 남쪽에 지정
		add(p2);// p2는 나머지에 지정
		setVisible(true);
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new practice03();
	}

}
