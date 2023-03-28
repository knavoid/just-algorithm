import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

	static int N;
	static int[] answer;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		// initialize
		N = Integer.parseInt(br.readLine());
		answer = new int[N + 1];
		Arrays.fill(answer, Integer.MAX_VALUE);
		answer[1] = 0;

		// solution
		for (int i = 2; i <= N; i++) {
			if (i % 3 == 0) {
				answer[i] = Math.min(answer[i], answer[i / 3] + 1);
			}
			if (i % 2 == 0) {
				answer[i] = Math.min(answer[i], answer[i / 2] + 1);
			}
			answer[i] = Math.min(answer[i], answer[i - 1] + 1);
		}

		// result
		System.out.println(answer[N]);
	}

}
