import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int K, W, H;
	static int[][] grid;
	static int[][][] minMove;
	static int[][] monkeyDirect = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
	static int[][] horseDirect = { { -2, 1 }, { -1, 2 }, { 1, 2 }, { 2, 1 }, 
			{ 2, -1 }, { 1, -2 }, { -1, -2 }, { -2, -1 } };

	static class Monkey {
		int x, y; // 원숭이의 좌표
		int h; // 말처럼 움직인 횟수

		Monkey(int x, int y, int h) {
			this.x = x;
			this.y = y;
			this.h = h;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		// initialize
		K = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		W = Integer.parseInt(st.nextToken());
		H = Integer.parseInt(st.nextToken());
		grid = new int[H][W];
		minMove = new int[H][W][K + 1];
		for (int i = 0; i < H; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < W; j++) {
				grid[i][j] = Integer.parseInt(st.nextToken());
				Arrays.fill(minMove[i][j], -1);
			}
		}

		// solution
		Queue<Monkey> q = new ArrayDeque<>();
		q.add(new Monkey(0, 0, 0));
		minMove[0][0][0] = 0;

		while (!q.isEmpty()) {
			Monkey monkey = q.poll();
			int x = monkey.x;
			int y = monkey.y;
			int h = monkey.h;
			// 도착했으면 끝내자
			if (x == H - 1 && y == W - 1) {
				System.out.println(minMove[x][y][h]);
				return;
			}
			// 나, 말처럼 움직일 수 있나?
			if (h < K) {
				for (int d = 0; d < 8; d++) {
					int dx = x + horseDirect[d][0];
					int dy = y + horseDirect[d][1];
					if (inRange(dx, dy) && grid[dx][dy] == 0 && minMove[dx][dy][h + 1] == -1) {
						q.add(new Monkey(dx, dy, h + 1));
						minMove[dx][dy][h + 1] = minMove[x][y][h] + 1;
					}
				}
			}
			// 나는 그냥 원숭이야..
			for (int d = 0; d < 4; d++) {
				int dx = x + monkeyDirect[d][0];
				int dy = y + monkeyDirect[d][1];
				if (inRange(dx, dy) && grid[dx][dy] == 0 && minMove[dx][dy][h] == -1) {
					q.add(new Monkey(dx, dy, h));
					minMove[dx][dy][h] = minMove[x][y][h] + 1;
				}
			}
		}

		System.out.println(-1);
	}

	static boolean inRange(int x, int y) {
		return 0 <= x && x < H && 0 <= y && y < W;
	}

}