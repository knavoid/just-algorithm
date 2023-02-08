import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

	static int N, M;
	static int[][] numbers;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());

		// initialize
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		numbers = new int[N + 1][N + 1];
		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= N; j++) {
				numbers[i][j] = Integer.parseInt(st.nextToken()) 
						+ numbers[i][j - 1] + numbers[i - 1][j] - numbers[i - 1][j - 1];
			}
		}

		// solution
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int x1 = Integer.parseInt(st.nextToken());
			int y1 = Integer.parseInt(st.nextToken());
			int x2 = Integer.parseInt(st.nextToken());
			int y2 = Integer.parseInt(st.nextToken());
			int sum = numbers[x2][y2] - (numbers[x1 - 1][y2] + numbers[x2][y1 - 1]) + numbers[x1 - 1][y1 - 1];
			bw.write(sum + "\n");
		}

		bw.flush();
		bw.close();
	}

}