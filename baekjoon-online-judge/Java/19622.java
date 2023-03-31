import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N; // 회의 수
	static int[][] meeting; // 회의 정보
	static int[] personnel; // 해당 인덱스까지의 회의를 선택했을 때의 최대 인원수 저장

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		// initialize
		N = Integer.parseInt(br.readLine());
		meeting = new int[N][3];
		personnel = new int[N];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 3; j++) {
				meeting[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		// solution
		personnel[0] = meeting[0][2];
		if (N > 1) {
			personnel[1] = Math.max(meeting[0][2], meeting[1][2]);
		}
		for (int i = 2; i < N; i++) {
			personnel[i] = Math.max(meeting[i][2] + personnel[i - 2], personnel[i - 1]);
		}

		// result
		System.out.println(personnel[N - 1]);
	}

}
