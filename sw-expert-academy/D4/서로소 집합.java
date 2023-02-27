import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

	private static int T;
	private static int n, m;
	private static int[] root; // 각 원소의 루트 원소를 기록

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb;
		T = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= T; tc++) {
			// initialize
			st = new StringTokenizer(br.readLine());
			sb = new StringBuilder().append("#" + tc + " ");
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			root = new int[n + 1];
			for (int i = 1; i <= n; i++) {
				root[i] = i;
			}

			// solution
			for (int i = 0; i < m; i++) {
				st = new StringTokenizer(br.readLine());
				int cmd = Integer.parseInt(st.nextToken());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				if (cmd == 0) { // 두 집합을 합치는 명령어
					if (findSet(a) != findSet(b)) {
						root[findSet(a)] = findSet(b);
					}
				} else { // 두 집합이 같은 집합인지 확인
					sb.append(findSet(a) != findSet(b) ? 0 : 1);
				}
			}

			// result
			System.out.println(sb);
		}
	}

	private static int findSet(int s) {
		return root[s] == s ? s : (root[s] = findSet(root[s]));
	}

}
