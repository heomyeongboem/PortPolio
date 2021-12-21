package practice;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class practice02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		InputStreamReader in = null;
		FileInputStream fin = null;// input은 들여오는거 output은 쓰는것
		try {
			fin = new FileInputStream("C:\\Users\\gblad\\eclipse-workspace\\11week\\hangul.txt");
			in = new InputStreamReader(fin, "MS949");
			int c;

			System.out.println("인코딩 문자 집합은 " + in.getEncoding());
			while ((c = in.read()) != -1)// EOF 가 아닐때까지 읽기
			{
				System.out.print((char) c);
			}
			in.close();
			fin.close();
		} catch (IOException e) {
			System.out.println("입출력 오류");
		}

	}

}
