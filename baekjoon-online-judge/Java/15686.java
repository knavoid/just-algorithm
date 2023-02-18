import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int N; // 도시 크기
	static int M; // 최대 치킨집의 개수
	static List<int[]> house = new ArrayList<>(); // 집들의 위치
	static List<int[]> chicken = new ArrayList<>(); // 치킨집들의 위치
	static int answer;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		// initialize
		answer = Integer.MAX_VALUE;
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= N; j++) {
				int value = Integer.parseInt(st.nextToken());
				if (value == 1) {
					house.add(new int[] { i, j });
				} else if (value == 2) {
					chicken.add(new int[] { i, j });
				}
			}
		}

		// solution
		selectChicken(0, 0, new ArrayList<>());

		// result
		System.out.println(answer);
	}

	static void selectChicken(int cnt, int now, List<int[]> select) {
		if (cnt == M) {
			// 도시의 치킨 거리 계산
			int cityChickenDist = 0;
			for (int[] hs : house) {
				int minDist = Integer.MAX_VALUE;
				for (int[] ck : select) {
					int dist = Math.abs(hs[0] - ck[0]) + Math.abs(hs[1] - ck[1]);
					minDist = Math.min(minDist, dist);
				}
				cityChickenDist += minDist;
			}
			answer = Math.min(answer, cityChickenDist);
			return;
		}
		for (int i = now; i < chicken.size(); i++) {
			select.add(chicken.get(i));
			selectChicken(cnt + 1, i + 1, select);
			select.remove(select.size() - 1);
		}
	}

}