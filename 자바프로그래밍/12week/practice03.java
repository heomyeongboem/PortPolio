package practice;

import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;

public class practice03 {

	static void printList(LinkedList<String> l) {
		Iterator<String> iterator = l.iterator();// 반복문 돌릴때 편하려고 씀 iterator
		while (iterator.hasNext()) // LinkedList로 생각하면 편함 없을때까지 반복
		{
			String e = iterator.next();
			String separator;
			if (iterator.hasNext())
				separator = "->";
			else
				separator = "\n";
			System.out.print(e + separator);
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		LinkedList<String> myList = new LinkedList<String>();
		myList.add("트랜스포머");
		myList.add("스타워즈");
		myList.add("매트릭스");
		myList.add(0, "터미네이터");
		myList.add(2, "아바타");

		Collections.sort(myList); // ㄱㄴㄷ 순서대로 정렬
		printList(myList);

		Collections.reverse(myList); // 요소의 순서를 반대로 정렬
		printList(myList);

		int index = Collections.binarySearch(myList, "아바타") + 1;// 바이너리 서치
		System.out.println("아바타는 " + index + "번째 요소입니다.");
	}

}
