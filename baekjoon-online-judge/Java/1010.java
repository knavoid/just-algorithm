import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int T; // 테스트 케이스 수
	static int west, east; // 서쪽의 사이트 수, 동쪽의 사이트 수

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		T = Integer.parseInt(br.readLine());
		while (T-- > 0) {
			// initialize
			st = new StringTokenizer(br.readLine());
			west = Integer.parseInt(st.nextToken());
			east = Integer.parseInt(st.nextToken());

			// result
			System.out.println(nCr(Math.max(west, east), Math.min(west, east)));
		}
	}

	static int nCr(int n, int r) {
		int[][] comb = new int[n + 1][r + 1];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= Math.min(i, r); j++) {
				if (j == 0 || j == i) {
					comb[i][j] = 1;
				} else {
					comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
				}
			}
		}
		return comb[n][r];
	}

}
