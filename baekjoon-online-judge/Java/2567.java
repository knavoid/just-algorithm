import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	private static int N; // 색종이의 수
	private static boolean[][] P = new boolean[101][101]; // 흰색 도화지 (true: 검은색)
	private static int[][] direct = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
	private static int answer;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		// initialize
		N = Integer.parseInt(br.readLine());
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			for (int r = x; r < x + 10; r++) {
				for (int c = y; c < y + 10; c++) {
					P[r][c] = true;
				}
			}
		}

		// solution
		for (int x = 0; x <= 100; x++) {
			for (int y = 0; y <= 100; y++) {
				if (P[x][y]) {
					for (int d = 0; d < 4; d++) {
						int dx = x + direct[d][0];
						int dy = y + direct[d][1];
						if (inRange(dx, dy) && !P[dx][dy]) {
							answer++;
						}
					}
				}
			}
		}

		// result
		System.out.println(answer);
	}

	private static boolean inRange(int x, int y) {
		return 0 <= x && x <= 100 && 0 <= y && y <= 100;
	}

}
