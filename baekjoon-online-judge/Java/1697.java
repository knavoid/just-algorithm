import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	private static int N; // 수빈이 위치
	private static int K; // 동생 위치
	private static final int MAX = 1000000;
	private static boolean[] visited = new boolean[MAX + 1];
	private static Queue<int[]> queue = new LinkedList<>();
	private static int answer;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// initialize
		N = sc.nextInt();
		K = sc.nextInt();

		// solution
		visited[N] = true;
		queue.add(new int[] { N, 0 });
		while (!queue.isEmpty()) {
			int[] n = queue.poll();
			int value = n[0];
			int time = n[1];
			
			// 동생을 찾았다.
			if (value == K) {
				answer = time;
				break;
			}
			
			// 걷기
			if (value > 0 && !visited[value - 1]) {
				visited[value - 1] = true;
				queue.add(new int[] { value - 1, time + 1 });
			}
			if (value < MAX && !visited[value + 1]) {
				visited[value + 1] = true;
				queue.add(new int[] { value + 1, time + 1 });
			}
			// 순간이동
			if (value * 2 < MAX && !visited[value * 2]) {
				visited[value * 2] = true;
				queue.add(new int[] { value * 2, time + 1 });
			}
		}

		// result
		System.out.println(answer);
	}

}
