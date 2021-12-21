package practice;

import java.awt.Container;
import java.awt.GridLayout;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class practice01 extends JFrame {

	practice01() {
		setTitle("GridLayout Sample");
		setSize(400, 300);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new GridLayout(4, 2, 5, 5));// GridLayout으로 4행 2열 이며 여기서 hgap은 가로 ,vgap은 세로 를 의미 GridLayout(int
												// rows, int cols, int hgap, int vgap)
		String[] str = { "이름", "학번", "학과", "과목" };// JLabel 에 넣을 텍스트값 입력
		for (int i = 0; i < 8; i++) { // 라벨은 짝수에만
			if (i % 2 == 0) {// 짝수일시 라벨 생성
				JLabel j = new JLabel(str[i / 2]);// 0,2,4,6 번째에 이름 학번 학과 과목 순의 라벨 생성
				c.add(j);// 컨테이너에 대입 무조건 해줘야됌 !!!
			} else {// 홀수 일시 라벨 생성
				JTextField jtf = new JTextField("");
				c.add(jtf);
			}
		}
		setVisible(true);
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new practice01();
	}
}
