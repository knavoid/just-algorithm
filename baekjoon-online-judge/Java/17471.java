import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	private static int N; // 구역의 수
	private static int[] P; // 각 구역의 인구수
	private static List<List<Integer>> M = new ArrayList<>(); // 각 구역의 인접한 구역 리스트
	private static int answer = -1;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		// initialize
		N = Integer.parseInt(br.readLine());
		P = new int[N + 1];
		for (int i = 0; i <= N; i++) {
			M.add(new ArrayList<>());
		}
		st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= N; i++) {
			P[i] = Integer.parseInt(st.nextToken());
		}
		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			for (int x = 0; x < n; x++) {
				int j = Integer.parseInt(st.nextToken());
				M.get(i).add(j);
			}
		}

		// 가능한 선택 경우를 모두 파악 (1: A구역, 0: B구역)
		int begin = (int) Math.pow(2, (N - 1));
		int end = (int) Math.pow(2, (N));
		for (int n = begin; n < end - 1; n++) {
			// 각각 나누어진 구역을 A, B 리스트에 저장
			List<Integer> A = new ArrayList<>();
			List<Integer> B = new ArrayList<>();
			for (int b = N - 1; b >= 0; b--) {
				if ((n & (1 << b)) != 0) {
					A.add(N - b);
				} else {
					B.add(N - b);
				}
			}
			// 두 리스트가 모두 연결되어 있는지 파악
			if (isLinked(A) && isLinked(B)) {
				// 각 구역의 인구수합 구하기
				int AP = 0, BP = 0;
				for (int a : A) {
					AP += P[a];
				}
				for (int b : B) {
					BP += P[b];
				}
				// 결과 계산
				int gap = Math.abs(AP - BP);
				answer = (answer == -1) ? gap : Math.min(answer, gap);
			}
		}

		// result
		System.out.println(answer);
	}

	// 넘겨 받은 구역 리스트가 모두 연결 되어있는지 파악
	private static boolean isLinked(List<Integer> area) {
		// area 리스트 내 구역의 방문 여부 표시
		Queue<Integer> queue = new ArrayDeque<>();
		boolean[] visited = new boolean[N + 1];
		queue.add(area.get(0));
		visited[queue.peek()] = true;
		while (!queue.isEmpty()) {
			int from = queue.poll();
			for (int to : M.get(from)) {
				if (!visited[to] && area.contains(to)) {
					queue.add(to);
					visited[to] = true;
				}
			}
		}
		// 방문 여부 파악
		for (int x : area) {
			if (!visited[x]) {
				return false;
			}
		}
		return true;
	}

}
