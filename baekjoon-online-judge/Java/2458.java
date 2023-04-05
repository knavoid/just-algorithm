import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N; // 학생들의 수
	static int M; // 키 비교 횟수
	static int[] tallCnt; // 각 학생보다 더 키가 큰 사람 수
	static int[] shortCnt; // 각 학생보다 더 키가 작은 사람 수
	static boolean[] visited; // 키 조사 여부
	static boolean[][] taller; // 키 비교 인접 행렬

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		// initialize
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		tallCnt = new int[N + 1];
		shortCnt = new int[N + 1];
		taller = new boolean[N + 1][N + 1];
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			taller[a][b] = true;
		}

		// solution
		for (int i = 1; i <= N; i++) {
			visited = new boolean[N + 1];
			visited[i] = true;
			measure(i, i);
		}

		// result
		int answer = 0;
		for (int i = 1; i <= N; i++) {
			if (tallCnt[i] + shortCnt[i] == N - 1) {
				answer++;
			}
		}
		System.out.println(answer);
	}

	static void measure(int begin, int curr) {
		for (int next = 1; next <= N; next++) {
			if (taller[curr][next] && !visited[next]) {
				tallCnt[begin]++;
				shortCnt[next]++;
				visited[next] = true;
				measure(begin, next);
			}
		}
	}

}
