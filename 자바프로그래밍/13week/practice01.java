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
		c.setLayout(new GridLayout(4, 2, 5, 5));// GridLayout���� 4�� 2�� �̸� ���⼭ hgap�� ���� ,vgap�� ���� �� �ǹ� GridLayout(int
												// rows, int cols, int hgap, int vgap)
		String[] str = { "�̸�", "�й�", "�а�", "����" };// JLabel �� ���� �ؽ�Ʈ�� �Է�
		for (int i = 0; i < 8; i++) { // ���� ¦������
			if (i % 2 == 0) {// ¦���Ͻ� �� ����
				JLabel j = new JLabel(str[i / 2]);// 0,2,4,6 ��°�� �̸� �й� �а� ���� ���� �� ����
				c.add(j);// �����̳ʿ� ���� ������ ����߉� !!!
			} else {// Ȧ�� �Ͻ� �� ����
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
