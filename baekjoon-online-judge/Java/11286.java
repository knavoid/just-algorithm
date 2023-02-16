import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Main {

	static int N;
	static PriorityQueue<Integer> pq = new PriorityQueue<>((o1, o2) -> {
		// 절댓값 오름차순, 값 오름차순
		return Math.abs(o1) != Math.abs(o2) ? Integer.compare(Math.abs(o1), Math.abs(o2)) : Integer.compare(o1, o2);
	});

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder answer = new StringBuilder();

		// initialize
		N = Integer.parseInt(br.readLine());
		for (int i = 0; i < N; i++) {
			int value = Integer.parseInt(br.readLine());
			if (value != 0) {
				pq.offer(value);
			} else if (!pq.isEmpty()) {
				answer.append(pq.poll() + "\n");
			} else {
				answer.append("0\n");
			}
		}

		// result
		System.out.println(answer);
	}

}
