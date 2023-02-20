import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		// initialize
		int N = Integer.parseInt(st.nextToken());
		int r = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());

		// result
		System.out.println(Z(r, c, (int) Math.pow(2, N) / 2));
	}

	// (r, c): 좌표, x: 한 변의 길이의 절반
	public static int Z(int r, int c, int x) {
		if (x > 0) {
			if (r < x && c < x) return Z(r, c, x / 2) + (x * x) * 0;
			else if (r < x && c >= x) return Z(r, c - x, x / 2) + (x * x) * 1;
			else if (r >= x && c < x) return Z(r - x, c, x / 2) + (x * x) * 2;
			else return Z(r - x, c - x, x / 2) + (x * x) * 3;
		}
		return 0;
	}

}
