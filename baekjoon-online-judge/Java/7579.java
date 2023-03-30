import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N; // 앱의 수
	static int M; // 확보해야할 메모리 크기
	static int[] memory; // 각 앱들이 사용중인 메모리 크기
	static int[] cost; // 각 앱들의 비활성화 비용
	static int[] maxMemory; // 총비용별 확보 가능한 최대 메모리

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		// initialize
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		memory = new int[N];
		cost = new int[N];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			memory[i] = Integer.parseInt(st.nextToken());
		}

		int costSum = 0; // 각 앱들의 비용 총합
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			cost[i] = Integer.parseInt(st.nextToken());
			costSum += cost[i];
		}
		maxMemory = new int[costSum + 1];

		// solution
		for (int i = 0; i < N; i++) {
			for (int j = costSum; j >= cost[i]; j--) {
				maxMemory[j] = Math.max(maxMemory[j], memory[i] + maxMemory[j - cost[i]]);
			}
		}

		// result
		for (int c = 0; c <= costSum; c++) {
			if (maxMemory[c] >= M) {
				System.out.println(c);
				break;
			}
		}
	}

}
