import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static int[][] meeting;
	static int answer;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		// initialize
		N = Integer.parseInt(br.readLine());
		meeting = new int[N][2];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			meeting[i][0] = Integer.parseInt(st.nextToken());
			meeting[i][1] = Integer.parseInt(st.nextToken());
		}

		// solution
		int time = 0; // 현재 시간
		Arrays.sort(meeting, (o1, o2) -> o1[1] != o2[1] ? o1[1] - o2[1] : o1[0] - o2[0]); // 끝나는 시간 오름차순, 시작 시간 오름차순
		for (int i = 0; i < N; i++) {
			if (time <= meeting[i][0]) {
				time = meeting[i][1];
				answer++;
			}
		}

		// result
		System.out.println(answer);
	}

}
