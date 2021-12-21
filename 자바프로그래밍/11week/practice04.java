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
			// FileOutputStream 생성 : 쓰기 객체
			for (int i = 0; i < b.length; i++) {
				fout.write(b[i]);// 쓰기
			}
			fout.close();// 파일 클로즈
		} catch (FileNotFoundException e) {
			e.printStackTrace();// 파일 못찾았을때
		} catch (IOException e) {
			e.printStackTrace();// 데이터 읽기 같은 입출력 문제가 있을 때 발생한다.
		}
		System.out.println("Test.out을 저장했습니다.");
		try {
			FileInputStream fin = new FileInputStream("test.out");
			// FileInputStream 생성 : 쓰기 객체

			// byte[] d = new byte[6]; // 파일로 부터 읽어올 값을 c라는 버퍼를 거쳐 d 배열에 담기

			byte[] d = fin.readAllBytes(); // 파일에 있는 값을 한번에 바이트 배열에 순차적으로 저장해줌 b[0]=7 b[1]=51 b[2]=3 ... b[5]=24

			// while ((c = fin.read()) != -1) // -1(EOF), 즉 문장의 끝이 나올때까지 읽기 { d[n] = (byte)
			// c;// 파일로 부터 읽어올 값을 c라는 버퍼를 거쳐 d 배열에 담기 n++;// b[0], b[1] , b[2] 이런식으로 b[6]
			// 까지에 값 저장 }

			// System.out.println(new String(d));

			fin.close();// 파일 클로즈
			// d배열에 담긴 값들을 출력해줌
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
