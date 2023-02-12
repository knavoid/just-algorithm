import java.io.IOException;
import java.util.Scanner;

public class Main {

	static int N; // 자리수
	static StringBuilder answer = new StringBuilder();

	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(System.in);

		// initialize
		N = input.nextInt();
		input.close();

		// solution
		interesting(2, 1);
		interesting(3, 1);
		interesting(5, 1);
		interesting(7, 1);

		// result
		System.out.println(answer);
	}

	// 숫자를 하나씩 붙이면서 확인
	static void interesting(int n, int len) {
		if (isPrime(n)) {
			if (len == N) {
				answer.append(n + "\n");
			} else {
				for (int i = 1; i <= 9; i += 2) {
					interesting(10 * n + i, len + 1);
				}
			}
		}
	}

	// 소수인지 판별
	static boolean isPrime(int n) {
		if (n < 2) {
			return false;
		}
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				return false;
			}
		}
		return true;
	}

}
