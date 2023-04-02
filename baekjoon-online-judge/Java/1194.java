import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_1194_달이차오른다가자_김성훈 {

	static int N, M; // 미로의 크기
	static int mx, my; // 민식이의 초기 위치
	static char[][] maze; // 미로
	static int[][][] minMove; // 각 위치, 보유중인 열쇠에 따른 최소 이동 횟수 저장
	static Queue<Minsik> queue = new ArrayDeque<>();
	static int[][] direct = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

	static class Minsik {
		int x, y; // 위치
		int key; // 가지고 있는 열쇠

		public Minsik(int x, int y, int key) {
			this.x = x;
			this.y = y;
			this.key = key;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		// initialize
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		maze = new char[N][M];
		minMove = new int[N][M][1 << 6];
		for (int i = 0; i < N; i++) {
			maze[i] = br.readLine().toCharArray();
			for (int j = 0; j < M; j++) {
				if (maze[i][j] == '0') {
					// 민식이 위치 저장
					mx = i;
					my = j;
					maze[i][j] = '.';
				}
				// 이동 횟수 배열 초기화
				Arrays.fill(minMove[i][j], -1);
			}
		}

		// solution
		minMove[mx][my][0] = 0;
		queue.add(new Minsik(mx, my, 0));
		while (!queue.isEmpty()) {
			Minsik ms = queue.poll();
			int x = ms.x;
			int y = ms.y;
			int k = ms.key;
			// 출구에 도착
			if (maze[ms.x][ms.y] == '1') {
				System.out.println(minMove[x][y][k]);
				return;
			}
			// 4방향 탐색
			for (int d = 0; d < 4; d++) {
				int dx = x + direct[d][0];
				int dy = y + direct[d][1];
				if (inRange(dx, dy) && maze[dx][dy] != '#') {
					char c = maze[dx][dy];
					// 열쇠
					if (Character.isLowerCase(c)) {
						int mask = 1 << (c - 'a');
						if (minMove[dx][dy][k | mask] == -1) {
							minMove[dx][dy][k | mask] = minMove[x][y][k] + 1;
							queue.add(new Minsik(dx, dy, k | mask));
						}
					}
					// 문
					else if (Character.isUpperCase(c)) {
						int mask = 1 << (c - 'A');
						// 열쇠가 있나?
						if ((k & mask) != 0 && minMove[dx][dy][k] == -1) {
							minMove[dx][dy][k] = minMove[x][y][k] + 1;
							queue.add(new Minsik(dx, dy, k));
						}
					}
					// 빈 칸 또는 출구
					else {
						if (minMove[dx][dy][k] == -1) {
							minMove[dx][dy][k] = minMove[x][y][k] + 1;
							queue.add(new Minsik(dx, dy, k));
						}
					}
				}
			}
		}

		System.out.println(-1);
	}

	static boolean inRange(int x, int y) {
		return 0 <= x && x < N && 0 <= y && y < M;
	}

	static void printMaze() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				System.out.print(maze[i][j] + " ");
			}
			System.out.println();
		}
	}

}
