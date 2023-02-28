import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	private static int V, E; // 정점과 간선의 개수
	private static int A, B, C; // 간선 정보
	private static boolean[] visited; // 신장트리 포함 여부
	private static List<List<Vertex>> M = new ArrayList<>(); // 인접 리스트
	private static PriorityQueue<Vertex> pq = new PriorityQueue<>((o1, o2) -> {
		return o1.weight - o2.weight; // 가중치 오름차순
	});
	private static int answer = 0;

	private static class Vertex {
		int number;
		int weight;

		Vertex(int number, int weight) {
			this.number = number;
			this.weight = weight;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		// initialize
		st = new StringTokenizer(br.readLine());
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		visited = new boolean[V + 1];
		for (int i = 0; i <= V; i++) {
			M.add(new ArrayList<>());
		}
		for (int i = 0; i < E; i++) {
			st = new StringTokenizer(br.readLine());
			A = Integer.parseInt(st.nextToken());
			B = Integer.parseInt(st.nextToken());
			C = Integer.parseInt(st.nextToken());
			M.get(A).add(new Vertex(B, C));
			M.get(B).add(new Vertex(A, C));
		}

		// Prim algorithm
		pq.add(new Vertex(1, 0));
		while (!pq.isEmpty()) {
			// 가중치가 가장 작은 정점을 신장트리에 추가
			Vertex now = pq.poll();
			if (visited[now.number]) {
				continue;
			}
			visited[now.number] = true;
			answer += now.weight;

			// 최소 가중치 업데이트
			for (Vertex next : M.get(now.number)) {
				if (!visited[next.number]) {
					pq.add(next);
				}
			}
		}

		// result
		System.out.println(answer);
	}

}