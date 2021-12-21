package practice;

public class practice3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// 배열 선언
		double[] s = { 1, 9, 4.5, 6.6, 5.7, -4.5 };

		// 버블정렬 ==> 큰놈부터 뒤로 차곡차곡 자리를 정해줘서 뒤에서 앞으로 자리를 정해주는 정렬
		for (int i = 0; i < s.length - 1; i++) {
//i<s.length - 1은 if(s[j] > s[j + 1])의 s[j + 1]때문에 이렇게 작성하였습니다.
			for (int j = 0; j < s.length - 1 - i; j++) {

				if (s[j] > s[j + 1]) {
					double temp = s[j];
					s[j] = s[j + 1];
					s[j + 1] = temp;
				}

			}

		}

		// 출력
		for (int i = 0; i < s.length; i++) {
			System.out.printf("%.1f ", s[i]);// 소수점 한자리까지 구하기 위해 .1f로 작성하였습니다.
		}

	}

}
