import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	static int N, M;
	static boolean[] selected;
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		// initialize
		N = input.nextInt();
		M = input.nextInt();
		selected = new boolean[N + 1];
		
		// solution
		numberSequence(0, new ArrayList<>());
	}
	
	static void numberSequence(int n, List<Integer> numbers) { // n: 선택한 숫자 개수
		// M개의 숫자를 선택한 경우
		if (n == M) {
			for (int number : numbers) {
				System.out.print(number + " ");
			}
			System.out.println();
			return;
		}
		// 1~N 까지 선택
		for (int i = 1; i <= N; i++) {
			if (!selected[i]) {
				selected[i] = true;
				numbers.add(i);
				numberSequence(n + 1, numbers);
				numbers.remove(n);
				selected[i] = false;
			}
		}
	}

}
