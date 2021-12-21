package practice;

import java.util.HashMap;
import java.util.Scanner;

public class practice04 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		HashMap<String, String> dic = new HashMap<String, String>(); // HashMap 쓰는 이유 : Key,Value 값에 따로 따로 넣기 위해서
		dic.put("baby", "아기");// put: Key,Value 값에 따로 따로 넣어주는 HashMap의 메소드
		dic.put("love", "사랑");
		dic.put("apple", "사과");

		Scanner sc = new Scanner(System.in);
		while (true) {
			System.out.print("찾고 싶은 단어는(영어단어만 가능합니다 고객님)?");
			String eng = sc.next();// key값인 영어단어를 입력받음
			if (eng.equals("exit"))// 입력 받은 단어가 exit와 같으면 종료
			{
				System.out.println("종료합니다...");
				break;
			}
			String Kor = dic.get(eng);// HashMap.get=Returns the value to which the specified key is mapped
			if (Kor == null)
				System.out.println(eng + "는 없는 단어 입니다.");// 없는 영어 단어(key)치면 null을 반환하기 때문에 가능
			else
				System.out.println(Kor);// 있으면 출력
		}
		sc.close();
	}

}
