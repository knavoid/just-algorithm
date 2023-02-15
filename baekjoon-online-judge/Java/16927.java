import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

	static int N, M, R;
	static int[][] arr;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());

		// initialize
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		arr = new int[N][M];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		// solution
		for (int v = 0; v < Math.min(N, M) / 2; v++) {
			int x1 = v, y1 = v;
			int x2 = N - v - 1, y2 = M - v - 1;
			int r = ((x2 - x1 + 1) + (y2 - y1 + 1)) * 2 - 4; // 둘레 길이
			int n = R % r;
			for (int i = 0; i < n; i++) {
				spin(x1, y1, x2, y2);
			}
		}

		// result
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				bw.write(arr[i][j] + " ");
			}
			bw.write("\n");
		}
		bw.flush();
		bw.close();
	}

	// (x1, y1)을 왼쪽 상단, (x2, y2)를 오른쪽 하단으로 하는 사각형을 회전
	static void spin(int x1, int y1, int x2, int y2) {
		int tmp = arr[x1][y1];
		// 윗부분 옮기기
		for (int y = y1; y < y2; y++) {
			arr[x1][y] = arr[x1][y + 1];
		}
		// 오른쪽 부분 옮기기
		for (int x = x1; x < x2; x++) {
			arr[x][y2] = arr[x + 1][y2];
		}
		// 아랫부분 옮기기
		for (int y = y2; y > y1; y--) {
			arr[x2][y] = arr[x2][y - 1];
		}
		// 왼쪽 부분 옮기기
		for (int x = x2; x > x1 + 1; x--) {
			arr[x][y1] = arr[x - 1][y1];
		}
		arr[x1 + 1][y1] = tmp;

	}

}
