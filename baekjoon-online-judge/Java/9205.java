import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int t; // 테스트 케이스 수
	static int n; // 편의점의 개수
	static int[][] loc; // 상근이의 집, 편의점, 페스티벌 위치
	static boolean[][] canGo;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		t = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= t; tc++) {
			// initialize
			n = Integer.parseInt(br.readLine());
			loc = new int[n + 2][2];
			for (int i = 0; i < n + 2; i++) {
				st = new StringTokenizer(br.readLine());
				loc[i][0] = Integer.parseInt(st.nextToken());
				loc[i][1] = Integer.parseInt(st.nextToken());
			}
			canGo = new boolean[n + 2][n + 2];
			for (int i = 0; i < n + 2; i++) {
				for (int j = i; j < n + 2; j++) {
					int dist = Math.abs(loc[i][0] - loc[j][0]) + Math.abs(loc[i][1] - loc[j][1]);
					if (dist <= 1000) {
						canGo[i][j] = true;
						canGo[j][i] = true;
					}
				}
			}

			// solution
			for (int k = 1; k <= n; k++) {
				for (int i = 0; i < n + 2; i++) {
					for (int j = 0; j < n + 2; j++) {
						if (canGo[i][k] && canGo[k][j]) {
							canGo[i][j] = true;
						}
					}
				}
			}

			// result
			System.out.println(canGo[0][n + 1] ? "happy" : "sad");
		}
	}

}
