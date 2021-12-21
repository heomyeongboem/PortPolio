package practice;

import java.util.Scanner;

public class practice1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int[] x = { 0, 0, 0, 0, 0, 1, 1, 1, 0, 0 };// 좌석
		int Reservation_First = 1;// 예약 반복문을 돌릴수 있는 키워드입니다.
		// 처음에는 1을 넣어 처음에는 무조껀 돌 수 있게 만들어줍니다.

		while (Reservation_First == 1) {
			System.out.printf("좌석을 예약하시겠습니까? (1 또는 0)");
			int Reservation = sc.nextInt();
			if (Reservation == 1) {
				System.out.println("현재의 예약 상태는 다음과 같습니다.");
				System.out.println("--------------------------");// 26개입니다.
				for (int i = 0; i < x.length; i++) {
					System.out.printf("%d ", i);
				}
				System.out.println();
				System.out.println("--------------------------");// 26개입니다.
				for (int i = 0; i < x.length; i++) {
					System.out.printf("%d ", x[i]);
				}
				while (Reservation == 1) { // 반복문을 사용하여 예약하려는데
					// 이미 그 자리가 예약된 자리라면 다시 받게 합니다. 물론 나갈것입니까?라고도 질문을받습니다.
					System.out.println();
					System.out.printf("몇 번째 좌석을 예약하시겠습니까?");
					int num = sc.nextInt();// 예약할 좌석 번호
					if (x[num] != 1) {// 1번자리가 x배열에서는 0번째 인덱스여서 num-1해줍니다.
						// 또한 1이 아니라는것은 예약안되어있으므로 예약할 수 있습니다.
						x[num] = 1;
						System.out.printf("%d", num);
						System.out.println("예약되었습니다.");
						Reservation = 0;// 반복문 나가는 방법
						break;
					} else {// 이미 예약된 자리이므로 다시 받습니다.
						System.out.println("이미 예약된 자리입니다.");
						Reservation = 0;// 1이면 반복문을 다시 돌기때문에 다시 예약할수 있고
						// 0이면 반복문 조건을 만족시키지 못하므로 반복문을 빠져나옵니다.

					}

				}
			}

			else {// 예약하기 싫은 사람이므로
				Reservation_First = 0;// 시스템 종료상태를 만들어줍니다.
			}

		}

		System.out.printf("시스템이 종료되었습니다.");
		sc.close();
	}

}
