package practice;

import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class practice03 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		FileWriter fout = null;
		try {
			fout = new FileWriter("C:\\Users\\gblad\\eclipse-workspace\\11week\\test.txt");
			while (true) {
				String line = sc.nextLine();
				if (line.length() == 0)
					break;
				fout.write(line, 0, line.length());
				fout.write("\r\n", 0, 2);// 총 세 번 엔터 누르면 종료
			}
			fout.close();
		} catch (IOException e) {
			System.out.println("입출력 오류");

		}

		sc.close();

	}

}
