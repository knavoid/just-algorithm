import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	private static int R, C;
	private static char[][] alphabet; // 입력한 알파벳
	private static int[][] direct = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
	private static int answer; // 말이 최대 몇칸을 지날 수 있는지

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		// initialize
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		alphabet = new char[R][];
		for (int i = 0; i < R; i++) {
			alphabet[i] = br.readLine().toCharArray();
		}

		// solution
		int used = 1 << (alphabet[0][0] - 'A');
		move(0, 0, 1, used);

		// result
		System.out.println(answer);
	}

	// (x, y): 좌표, cnt: 지나온 칸 개수, used: 알파벳 사용 여부 비트
	private static void move(int x, int y, int cnt, int used) {
		// 탐색 결과 및 최대 이동 칸 업데이트
		answer = Math.max(answer, cnt);

		// 인접한 칸으로 이동
		for (int d = 0; d < 4; d++) {
			int dx = x + direct[d][0];
			int dy = y + direct[d][1];
			if (inRange(dx, dy)) {
				int mask = 1 << (alphabet[dx][dy] - 'A');
				if ((used & mask) == 0) {
					move(dx, dy, cnt + 1, used | mask);
				}
			}
		}
	}

	private static boolean inRange(int x, int y) {
		return 0 <= x && x < R && 0 <= y && y < C;
	}

}