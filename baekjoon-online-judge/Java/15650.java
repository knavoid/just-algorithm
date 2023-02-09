import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	static int N, M;
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		// initialize
		N = input.nextInt();
		M = input.nextInt();
		
		// solution
		numberSequence(0, 1, new ArrayList<>());
	}
	
	static void numberSequence(int n, int b, List<Integer> numbers) {
		if (n == M) {
			for (int number : numbers) {
				System.out.print(number + " ");
			}
			System.out.println();
			return;
		}
		for (int i = b; i <= N; i++) {
			numbers.add(i);
			numberSequence(n + 1, i + 1, numbers);
			numbers.remove(n);
		}
	}

}
