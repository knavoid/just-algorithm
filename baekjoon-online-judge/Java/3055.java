import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int R, C; // 지도 크기
	static int Dx, Dy; // 비버의 굴 좌표
	static char[][] map; // 지도 정보
	static boolean[][] visited; // 고슴도치 방문 정보
	static Queue<int[]> water = new ArrayDeque<>(); // 물 이동
	static Queue<int[]> hedgehog = new ArrayDeque<>(); // 고슴도치 이동
	static int[][] direct = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		// initialize
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		map = new char[R][C];
		visited = new boolean[R][C];
		for (int i = 0; i < R; i++) {
			map[i] = br.readLine().toCharArray();
			for (int j = 0; j < C; j++) {
				if (map[i][j] == '*') { // 물
					water.add(new int[] { i, j });
				} else if (map[i][j] == 'S') { // 고슴도치
					hedgehog.add(new int[] { i, j, 0 });
					map[i][j] = '.';
				} else if (map[i][j] == 'D') { // 비버의 굴
					Dx = i;
					Dy = j;
				}
			}
		}

		// solution
		while (!hedgehog.isEmpty()) {
			// 물이 먼저 퍼지자
			Queue<int[]> water_ = new ArrayDeque<>();
			while (!water.isEmpty()) {
				int[] w = water.poll();
				int wx = w[0];
				int wy = w[1];
				for (int d = 0; d < 4; d++) {
					int dwx = wx + direct[d][0];
					int dwy = wy + direct[d][1];
					if (inRange(dwx, dwy) && map[dwx][dwy] == '.') {
						map[dwx][dwy] = '*';
						water_.add(new int[] { dwx, dwy });
					}
				}
			}
			water = new ArrayDeque<>(water_);

			// 고슴도치야 가자
			Queue<int[]> hedgehog_ = new ArrayDeque<>();
			while (!hedgehog.isEmpty()) {
				int[] h = hedgehog.poll();
				int hx = h[0];
				int hy = h[1];
				int ht = h[2];
				// 비버의 굴이야!
				if (hx == Dx && hy == Dy) {
					System.out.println(ht);
					return;
				}
				for (int d = 0; d < 4; d++) {
					int dhx = hx + direct[d][0];
					int dhy = hy + direct[d][1];
					if (inRange(dhx, dhy) && (map[dhx][dhy] == '.' || map[dhx][dhy] == 'D') && !visited[dhx][dhy]) {
						visited[dhx][dhy] = true;
						hedgehog_.add(new int[] { dhx, dhy, ht + 1 });
					}
				}
			}
			hedgehog = new ArrayDeque<>(hedgehog_);
		}

		System.out.println("KAKTUS");
	}

	static boolean inRange(int x, int y) {
		return 0 <= x && x < R && 0 <= y && y < C;
	}

}
