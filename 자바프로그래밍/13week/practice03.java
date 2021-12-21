package practice;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.TextField;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

class Panel1 extends JPanel {// ���� ���� ����, �ݱ� ,������ ��ư�� ���� �г��� ������ Ŭ����
	public Panel1() {
		setBackground(Color.LIGHT_GRAY);
		// setLayout(new FlowLayout());
		add(new JButton("����"));// Ŭ���� �ȿ� �����ϸ� '.add' ������ ���� add�� �ص� �߰��� �ǳ� ���ϴ�.
		add(new JButton("�ݱ�"));// �ݱ� ��ư �߰�
		add(new JButton("������"));// ������ ��ư �߰�
	}
}

class Panel2 extends JPanel {
	public Panel2() {
		setLayout(null);
		for (int i = 0; i < 10; i++) {// 10����
			int x = (int) (Math.random() * 250);// ���� x���� ������
			int y = (int) (Math.random() * 250);// ���� y���� ������
			JLabel label = new JLabel("$");// $���� ����
			label.setForeground(Color.red); // $������ ����� ������ ����
			label.setLocation(x, y); // $������ ��ġ ����
			label.setSize(10, 10); // $ũ�⸦ 10*10 �ȼ��� ����
			label.setOpaque(true); // Opaque���� true�� �̸� ������ �־�� ������ ����ȴ�.
			add(label);// ���� Panel2 �гο� �߰�
		}
	}
}

class Panel3 extends JPanel {
	public Panel3() {
		setBackground(Color.YELLOW); // ��� ��������� �����
		add(new JButton("Word Input"));// ��ư ������ �߰�
		add(new TextField(15)); // 15���ڱ��� ���� �� �ִ� �ؽ�Ʈ �ʵ� ���� �� �߰�
	}
}

public class practice03 extends JFrame {

	practice03() {
		setTitle("���� ���� �г��� ���� ������");
		setSize(300, 300);// ũ�� 300*300 �ȼ��� ����
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // Frame�� �⺻������ �ִ� ������ ��ư �������
		Panel1 p1 = new Panel1();
		Panel2 p2 = new Panel2();
		Panel3 p3 = new Panel3();
		add(p1, BorderLayout.NORTH); // BorderLayout���� ���ʿ� ����
		add(p3, BorderLayout.SOUTH); // BorderLayout���� ���ʿ� ����
		add(p2);// p2�� �������� ����
		setVisible(true);
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new practice03();
	}

}
