import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int R, C, N;
	static char[][] grid;
	static Queue<int[]> queue = new ArrayDeque<>();
	static int[][] direct = { { 0, 0 }, { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		// initialize
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		grid = new char[R][C];
		for (int r = 0; r < R; r++) {
			grid[r] = br.readLine().toCharArray();
		}

		// solution
		if (N > 8) {
			N = (N - 1) % 4 + 5;
		}
		for (int time = 1; time < N; time++) {
			// 시간이 홀수이면
			if (time % 2 == 1) {
				for (int r = 0; r < R; r++) {
					for (int c = 0; c < C; c++) {
						// 폭탄 설치
						if (grid[r][c] == '.') {
							grid[r][c] = 'O';
						}
						// 폭탄 큐에 넣어
						else {
							queue.add(new int[] { r, c });
						}
					}
				}
			}
			// 시간이 짝수이면
			else {
				// 폭탄 터져
				while (!queue.isEmpty()) {
					int[] p = queue.poll();
					for (int d = 0; d < 5; d++) {
						int dr = p[0] + direct[d][0];
						int dc = p[1] + direct[d][1];
						if (0 <= dr && dr < R && 0 <= dc && dc < C) {
							grid[dr][dc] = '.';
						}
					}
				}
				// 폭탄 큐에 넣어
				for (int r = 0; r < R; r++) {
					for (int c = 0; c < C; c++) {
						if (grid[r][c] == 'O') {
							queue.add(new int[] { r, c });
						}
					}
				}
			}
		}

		// result
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				System.out.print(grid[r][c]);
			}
			System.out.println();
		}
	}

}
