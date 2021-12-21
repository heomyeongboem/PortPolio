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
		setTitle("���� ������");
		setSize(400, 400);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		Container c = getContentPane();// �г��� ���� �� �ִ� ���� ū ���(���� ���� �г��� ������ ������� �г��� ��ġ�� ������־�ߵǴµ� �갡 �� ����� �� ����)
		JPanel jp1 = new JPanel();// �г� pn ����
		JPanel jp2 = new JPanel();// �г� ps ����
		JPanel jp3 = new JPanel();// �г� pc ����
		jp1.setBackground(Color.LIGHT_GRAY);// pn �г��� LIGHT_GRAY�� ����
		jp3.setLayout(new GridLayout(4, 4));// pc �� ���̾ƿ��� GridLayout���� 4*4����� ����
		jp2.setBackground(Color.YELLOW);//// ps �г��� ������� ����
		c.add(jp3);// �����̳ʿ� pc�г� ����
		c.add(jp1, BorderLayout.NORTH);// �����̳� ���ʿ� borderlayout���� pn �г� ����
		c.add(jp2, BorderLayout.SOUTH);// �����̳� ���ʿ� borderlayout���� ps �г� ����
		JLabel l1 = new JLabel("�����Է�");// �� �����
		JTextField tf1 = new JTextField(10);// ���� �Է� �� �� �ִ� �ؽ�Ʈ �ʵ�
		jp1.add(l1);// �󺧰�
		jp1.add(tf1);// �ؽ�Ʈ �ʵ带 pn �гξȿ� �־���
		JLabel l2 = new JLabel("�����");// �󺧰�
		JTextField tf2 = new JTextField(10);// �ؽ�Ʈ �ʵ带 ����
		jp2.add(l2);// �󺧰�
		jp2.add(tf2);// �ؽ�Ʈ �ʵ带 ps�гο� �־���
		for (int i = 0; i < 16; i++) {
			JButton b = new JButton();// 16���� ��ư�� ����
			String[] str = { "CE", "Enter", "+", "-", "x", "/" };
			jp3.add(b);
			if (i < 10) {
				b.setText(i + "");// b ��ư�� ���� �������
			} else {
				b.setText(str[i - 10]);// 10-10 �ϸ� "CE" 11-10 �ϸ� "Enter" ������ str �迭�� �ִ� ���� ���������� �־���
			}

			if (i > 11) {// 12�� ��ư ���ʹ� CYAN���� ������ �����.
				b.setBackground(Color.CYAN);
				b.setOpaque(true);
			}

		}
		setVisible(true);// ���̰� ����

	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new practice02();// practice02 ����
	}

}
