import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {

	private static int T;
	private static int N, M;
	private static int[] root; // 각 원소의 루트 원소를 기록

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb;

		T = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= T; tc++) {
			// initialize
			st = new StringTokenizer(br.readLine());
			sb = new StringBuilder("#" + tc + " ");
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			root = new int[N + 1];
			for (int i = 1; i <= N; i++) {
				root[i] = i;
			}

			// solution
			for (int i = 0; i < M; i++) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				// 둘이 같은 무리가 아니면 같은 무리로 만들자
				if (findSet(a) != findSet(b)) {
					root[findSet(a)] = findSet(b);
				}
			}

			// 무리의 수 세기
			int count = 0;
			boolean[] exist = new boolean[N + 1];
			for (int i = 1; i <= N; i++) {
				exist[findSet(root[i])] = true;
			}
			for (int i = 1; i <= N; i++) {
				if (exist[i]) {
					count++;
				}
			}
			sb.append(count);

			// result
			System.out.println(sb);
		}
	}

	private static int findSet(int s) {
		return root[s] == s ? s : (root[s] = findSet(root[s]));
	}

}
