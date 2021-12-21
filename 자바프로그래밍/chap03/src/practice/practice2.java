package practice;

import java.util.Scanner;

public class practice2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);

		System.out.println("1:µ¡¼À, 2:»¬¼À, 3:°ö¼À, 4:³ª´°¼À, 5:³ª¸ÓÁö ¿¬»ê");
		int z = sc.nextInt();

		System.out.printf("¿¬»êÀ» ¿øÇÏ´Â Á¤¼ö µÎ°³¸¦ ÀÔ·ÂÇÏ¼¼¿ä:");
		int x = sc.nextInt();
		int y = sc.nextInt();

		if (z == 1)
			System.out.printf("%d+%d=%d", x, y, x + y);
		if (z == 2)
			System.out.printf("%d-%d=%d", x, y, x - y);
		if (z == 3)
			System.out.printf("%d*%d=%d", x, y, x * y);
		if (z == 4)
			System.out.printf("%d/%d=%d", x, y, x / y);
		if (z == 5)
			System.out.println(+x + "%" + y + "=" + (x % y));
		else
			System.out.println("Wrong input");
		sc.close();
	}

}
