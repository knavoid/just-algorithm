import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.stream.Stream;

public class Main {

	static int N; // 스위치의 개수
	static int M; // 학생 수
	static int[] S; // 스위치 상태

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		// initialize
		N = Integer.parseInt(br.readLine());
		S = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
		M = Integer.parseInt(br.readLine());

		// solution
		for (int i = 0; i < M; i++) {
			int[] input = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
			int gender = input[0];
			int number = input[1];
			// 성별에 따라서 스위치 상태 변경
			if (gender == 1) {
				for (int j = number; j <= N; j += number) {
					S[j - 1] ^= 1;
				}
			} else {
				int i1 = number - 1;
				int i2 = number + 1;
				while (1 <= i1 && i2 <= N && S[i1 - 1] == S[i2 - 1]) {
					i1--;
					i2++;
				}
				for (int j = i1 + 1; j <= i2 - 1; j++) {
					S[j - 1] ^= 1;
				}
			}
		}

		// result
		for (int i = 0; i < N; i++) {
			bw.write(S[i] + " ");
			if ((i + 1) % 20 == 0) {
				bw.write("\n");
			}
		}

		bw.flush();
		bw.close();
	}

}