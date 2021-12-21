package practice;

import java.util.Scanner;

public class practice4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[][] a = new int[3][3];// a행렬 선언
		int[][] b = new int[3][3];// b행렬 선언
		Scanner sc = new Scanner(System.in);

		// a행렬에 값 입력
		System.out.println("a행렬을 입력하세요.a행렬은 3*3행렬입니다");
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[i].length; j++) {
				a[i][j] = sc.nextInt();
			}
		}

		// b행렬에 값 입력
		System.out.println("b행렬을 입력하세요.b행렬은 3*3행렬입니다");
		for (int i = 0; i < b.length; i++) {
			for (int j = 0; j < b[i].length; j++) {
				b[i][j] = sc.nextInt();
			}
		}

		sc.close();

		// a행렬+b행렬
		System.out.println("a행렬+b행렬");
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[i].length; j++) {
				System.out.printf("%d ", a[i][j] + b[i][j]);
			}
			// 여기다가 println()을 넣은 이유는 행이 바뀔때마다 줄을 바꿔주면 이쁠 것 같아서 그랬습니다.
			System.out.println();
		}

	}

}
