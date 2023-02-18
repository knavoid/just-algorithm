import java.util.Arrays;
import java.util.Scanner;

public class Main {

	static int[] numbers = new int[9];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// initialize
		for (int i = 0; i < 9; i++) {
			numbers[i] = sc.nextInt();
		}
		
		// solution
		int sum = Arrays.stream(numbers).sum();
		for (int i = 0; i < 8; i++) {
			for (int j = i + 1; j < 9; j++) {
				if (sum - (numbers[i] + numbers[j]) == 100) {
					// 결과 출력하고 종료
					for (int k = 0; k < 9; k++) {
						if (k != i && k != j) {
							System.out.println(numbers[k]);
						}
					}
					return;
				}
			}
		}
	}
	
}
