package practice;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class practice02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		InputStreamReader in = null;
		FileInputStream fin = null;// input�� �鿩���°� output�� ���°�
		try {
			fin = new FileInputStream("C:\\Users\\gblad\\eclipse-workspace\\11week\\hangul.txt");
			in = new InputStreamReader(fin, "MS949");
			int c;

			System.out.println("���ڵ� ���� ������ " + in.getEncoding());
			while ((c = in.read()) != -1)// EOF �� �ƴҶ����� �б�
			{
				System.out.print((char) c);
			}
			in.close();
			fin.close();
		} catch (IOException e) {
			System.out.println("����� ����");
		}

	}

}
