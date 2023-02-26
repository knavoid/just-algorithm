import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	private static int N; // 사람의 수
	private static int M; // 친구 관계의 수
	private static boolean[] visited; // 친구 조사 여부
	private static List<List<Integer>> friend = new ArrayList<>(); // 친구 관계 인접 리스트
	private static int answer;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		// initialize
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		visited = new boolean[N];
		for (int i = 0; i < N; i++) {
			friend.add(new ArrayList<>());
		}
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			friend.get(a).add(b);
			friend.get(b).add(a);
		}

		// solution
		for (int i = 0; i < N; i++) {
			visited[i] = true;
			areYouFriend(i, 0);
			visited[i] = false;
			if (answer == 1) {
				break;
			}
		}

		// result
		System.out.println(answer);
	}

	private static void areYouFriend(int me, int depth) {
		if (answer == 1) {
			return;
		}
		// 친구의친구의친구의친구가 존재하면
		if (depth == 4) {
			answer = 1;
			return;
		}
		// 너 내 친구니?
		for (int you : friend.get(me)) {
			if (!visited[you]) {
				visited[you] = true;
				areYouFriend(you, depth + 1);
				visited[you] = false;
			}
		}
	}

}
