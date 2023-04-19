import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static int[] finish; // 각 작업이 끝나는 최소 시간
	static int answer; // 모든 작업이 끝나는 최소 시간

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		// initialize
		N = Integer.parseInt(br.readLine());
		finish = new int[N + 1];

		// solution
		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			int time = Integer.parseInt(st.nextToken());
			int count = Integer.parseInt(st.nextToken()); // 선행 작업 수
			int earliest = (count == 0) ? 0 : Integer.MIN_VALUE;
			while (count-- > 0) {
				int task = Integer.parseInt(st.nextToken());
				earliest = Math.max(earliest, finish[task]);
			}
			answer = Math.max(answer, finish[i] = earliest + time);
		}

		// result
		System.out.println(answer);
	}

}
