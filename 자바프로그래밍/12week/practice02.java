package practice;

import java.util.Vector;

public class practice02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Vector<Integer> v = new Vector<Integer>();
		v.add(5);
		v.add(4);
		v.add(-1);

		v.add(2, 100);

		int Sum = 0;
		System.out.println("벡터 내의 요소 객체 수 : " + v.size());
		System.out.println("벡터의 현재 용량 : " + v.capacity());
		for (int i = 0; i < v.size(); i++) {
			System.out.println(v.get(i));// 모든 원소 출력
			Sum += v.get(i);
		}

		System.out.println("벡터에 있는 정수의 합 : " + Sum);
	}

}
