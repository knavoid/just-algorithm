import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

	static int N; // 접시의 수
	static int d; // 초밥의 가짓수
	static int k; // 연속해서 먹는 접시의 수
	static int c; // 쿠폰 번호
	static int[] sushi; // 초밥 번호들
	static Map<Integer, Integer> count; // 각 초밥의 개수 (k개 선택)
	static int answer; // 최대 초밥 종류의 수

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		// initialize
		N = Integer.parseInt(st.nextToken());
		d = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		sushi = new int[N];
		for (int i = 0; i < N; i++) {
			sushi[i] = Integer.parseInt(br.readLine());
		}
		count = new HashMap<>();
		count.put(c, 1); // 쿠폰 초밥 하나 선택

		// 처음 k개 초밥 선택
		for (int i = 0; i < k; i++) {
			count.put(sushi[i], count.getOrDefault(sushi[i], 0) + 1);
		}

		// 하나씩 이동하면서 살펴보자
		for (int i = 0; i < N - 1; i++) {
			// 초밥 하나 빼기
			count.put(sushi[i], count.get(sushi[i]) - 1);
			if (count.get(sushi[i]) == 0) {
				count.remove(sushi[i]);
			}
			// 초밥 하나 더하기
			count.put(sushi[(i + k) % N], count.getOrDefault(sushi[(i + k) % N], 0) + 1);

			// 정답 업데이트
			answer = Math.max(answer, count.size());
		}

		// result
		System.out.println(answer);
	}

}
