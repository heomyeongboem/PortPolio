package pratice;

import java.util.Scanner;

public class practice4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		double t;// 입력 받을 시간
		double x;// 위치
		double a = 9.81;

		Scanner sc = new Scanner(System.in);
		t = sc.nextDouble();

		x = 0.5 * a * t * t;// 물체가 얼마나 이동했느냐에 대한 공식은 1/2 *a*t^2 (a=v/t ==> v=t*a이므로)

		if (x > 1000)
			x = 1000;// 1000m에서 떨어뜨렸는데 1000m 이상을 갈 수는 없으므로 1000m 이상시 1000m로 고정

		else {
			System.out.printf("%fm", x);// 입력 받은것을 토대로 식에 대입하여 위치 값을 출력
		}
		sc.close();
	}

}
