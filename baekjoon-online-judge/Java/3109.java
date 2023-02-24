import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	private static int R, C;
	private static char[][] map; // 맵 상태
	private static int[][] direct = { { -1, 1 }, { 0, 1 }, { 1, 1 } };
	private static int answer;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		// initialize
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		map = new char[R][];
		for (int i = 0; i < R; i++) {
			map[i] = br.readLine().toCharArray();
		}

		// solution
		for (int i = 0; i < R; i++) {
			if (pipeline(i, 0)) {
				answer++;
			}
		}

		// result
		System.out.println(answer);
	}

	public static boolean pipeline(int x, int y) {
		// 나 여기에 한번 설치 해봤었어
		map[x][y] = 'o';
		// 빵집 도착!
		if (y == C - 1) {
			return true;
		}
		// 각 방향으로 이동해보자
		for (int d = 0; d < 3; d++) {
			int dx = x + direct[d][0];
			int dy = y + direct[d][1];
			if (inRange(dx, dy) && map[dx][dy] == '.' && pipeline(dx, dy)) {
				return true;
			}
		}
		return false;
	}

	public static boolean inRange(int x, int y) {
		return 0 <= x && x < R && 0 <= y && y < C;
	}

}
