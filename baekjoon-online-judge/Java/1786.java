import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	static String T, P;
	static int[] pi; // 부분 일치 테이블
	static int count;
	static StringBuilder index = new StringBuilder();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		// initialize
		T = br.readLine();
		P = br.readLine();

		// 패턴에 대한 부분 일치 테이블 생성
		pi = new int[P.length()];
		int i = 1, j = 0;
		while (i < P.length()) {
			if (P.charAt(i) == P.charAt(j)) {
				pi[i++] = j++ + 1;
			} else if (j == 0) {
				pi[i++] = j;
			} else {
				j = pi[j - 1];
			}
		}

		// KMP
		i = j = 0;
		while (i < T.length()) {
			if (T.charAt(i) == P.charAt(j)) {
				i++;
				j++;
				// 패턴의 길이만큼 일치하면
				if (j == P.length()) {
					count++;
					index.append(i - j + 1).append(' ');
					j = pi[j - 1];
				}
			} else if (j == 0) {
				i++;
			} else {
				j = pi[j - 1];
			}
		}

		// result
		System.out.println(count);
		System.out.println(index);
	}

}
