package practice;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class practice02 extends JFrame {

	practice02() {
		setTitle("계산기 프레임");
		setSize(400, 400);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		Container c = getContentPane();// 패널을 담을 수 있는 가장 큰 용기(쉽게 말해 패널을 여러개 만들려면 패널의 위치를 배분해주어야되는데 얘가 그 어려운 걸 해줌)
		JPanel jp1 = new JPanel();// 패널 pn 생성
		JPanel jp2 = new JPanel();// 패널 ps 생성
		JPanel jp3 = new JPanel();// 패널 pc 생성
		jp1.setBackground(Color.LIGHT_GRAY);// pn 패널은 LIGHT_GRAY로 지정
		jp3.setLayout(new GridLayout(4, 4));// pc 의 레이아웃은 GridLayout으로 4*4행렬을 가짐
		jp2.setBackground(Color.YELLOW);//// ps 패녈은 노란색을 가짐
		c.add(jp3);// 컨테이너에 pc패널 삽입
		c.add(jp1, BorderLayout.NORTH);// 컨테이너 북쪽에 borderlayout으로 pn 패널 삽입
		c.add(jp2, BorderLayout.SOUTH);// 컨테이너 남쪽에 borderlayout으로 ps 패널 삽입
		JLabel l1 = new JLabel("수십입력");// 라벨 만들기
		JTextField tf1 = new JTextField(10);// 값을 입력 할 수 있는 텍스트 필드
		jp1.add(l1);// 라벨과
		jp1.add(tf1);// 텍스트 필드를 pn 패널안에 넣어줌
		JLabel l2 = new JLabel("계산결과");// 라벨과
		JTextField tf2 = new JTextField(10);// 텍스트 필드를 생성
		jp2.add(l2);// 라벨과
		jp2.add(tf2);// 텍스트 필드를 ps패널에 넣어줌
		for (int i = 0; i < 16; i++) {
			JButton b = new JButton();// 16개의 버튼을 만듦
			String[] str = { "CE", "Enter", "+", "-", "x", "/" };
			jp3.add(b);
			if (i < 10) {
				b.setText(i + "");// b 버튼에 값을 집어넣음
			} else {
				b.setText(str[i - 10]);// 10-10 하면 "CE" 11-10 하면 "Enter" 순으로 str 배열에 있는 값을 순차적으로 넣어줌
			}

			if (i > 11) {// 12번 버튼 부터는 CYAN색을 가지게 만든다.
				b.setBackground(Color.CYAN);
				b.setOpaque(true);
			}

		}
		setVisible(true);// 보이게 만듦

	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new practice02();// practice02 실행
	}

}
