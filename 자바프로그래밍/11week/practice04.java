package practice;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class practice04 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		byte b[] = { 7, 51, 3, 4, -1, 24 };

		try {
			FileOutputStream fout = new FileOutputStream("test.out");
			// FileOutputStream ���� : ���� ��ü
			for (int i = 0; i < b.length; i++) {
				fout.write(b[i]);// ����
			}
			fout.close();// ���� Ŭ����
		} catch (FileNotFoundException e) {
			e.printStackTrace();// ���� ��ã������
		} catch (IOException e) {
			e.printStackTrace();// ������ �б� ���� ����� ������ ���� �� �߻��Ѵ�.
		}
		System.out.println("Test.out�� �����߽��ϴ�.");
		try {
			FileInputStream fin = new FileInputStream("test.out");
			// FileInputStream ���� : ���� ��ü

			// byte[] d = new byte[6]; // ���Ϸ� ���� �о�� ���� c��� ���۸� ���� d �迭�� ���

			byte[] d = fin.readAllBytes(); // ���Ͽ� �ִ� ���� �ѹ��� ����Ʈ �迭�� ���������� �������� b[0]=7 b[1]=51 b[2]=3 ... b[5]=24

			// while ((c = fin.read()) != -1) // -1(EOF), �� ������ ���� ���ö����� �б� { d[n] = (byte)
			// c;// ���Ϸ� ���� �о�� ���� c��� ���۸� ���� d �迭�� ��� n++;// b[0], b[1] , b[2] �̷������� b[6]
			// ������ �� ���� }

			// System.out.println(new String(d));

			fin.close();// ���� Ŭ����
			// d�迭�� ��� ������ �������
			for (int i = 0; i < d.length; i++) {
				System.out.print(d[i] + " ");
			}

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

}
