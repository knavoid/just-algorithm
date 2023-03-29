import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int n, k;
	static int[] coin; // 동전 가치
	static int[] minCnt; // 동전 가치에 대한 최소 동전 개수

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		// initialize
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		coin = new int[n];
		for (int i = 0; i < n; i++) {
			coin[i] = Integer.parseInt(br.readLine());
		}
		minCnt = new int[k + 1];
		Arrays.fill(minCnt, Integer.MAX_VALUE);
		minCnt[0] = 0; // 0원을 위한 동전 수는 0개

		// solution
		for (int i = 1; i <= k; i++) {
			for (int c : coin) {
				if (i >= c && minCnt[i - c] != Integer.MAX_VALUE) {
					minCnt[i] = Math.min(minCnt[i], minCnt[i - c] + 1);
				}
			}
		}

		// result
		System.out.println(minCnt[k] != Integer.MAX_VALUE ? minCnt[k] : -1);
	}

}
