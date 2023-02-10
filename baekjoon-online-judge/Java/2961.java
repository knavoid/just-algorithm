import java.util.Scanner;

public class Main {

	static int N;
	static int[][] flavor;
	static int answer = Integer.MAX_VALUE;

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		// initialize
		N = input.nextInt();
		flavor = new int[N][2];
		for (int i = 0; i < N; i++) {
			flavor[i][0] = input.nextInt();
			flavor[i][1] = input.nextInt();
		}
		input.close();

		// solution
		selectFlavor(0, 0, 1, 0);

		// result
		System.out.println(answer);
	}
	
	// n : 선택할 재료 순서, c : 선택한 재료 수, s : 신맛, b : 쓴만
	static void selectFlavor(int n, int c, int s, int b) {
		// N개의 재료 선택이 모두 끝난 경우
		if (n == N) {
			if (c > 0) {
				answer = Math.min(answer, Math.abs(s - b));
			}
			return;
		}
		// 현재 재료를 선택하는 경우
		selectFlavor(n + 1, c + 1, s * flavor[n][0], b + flavor[n][1]);
		// 현재 재료를 선택하지 않는 경우
		selectFlavor(n + 1, c, s, b);
	}

}
