import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static int[][] RGB;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		// initializes
		N = Integer.parseInt(br.readLine());
		RGB = new int[N][3];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 3; j++) {
				RGB[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		// solution (Dynamic programming)
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < 3; j++) {
				RGB[i][j] += (j == 0) ? Math.min(RGB[i - 1][1], RGB[i - 1][2])
						: (j == 1) ? Math.min(RGB[i - 1][0], RGB[i - 1][2]) : Math.min(RGB[i - 1][0], RGB[i - 1][1]);
			}
		}

		// result
		System.out.println(Math.min(RGB[N - 1][0], Math.min(RGB[N - 1][1], RGB[N - 1][2])));
	}

}
