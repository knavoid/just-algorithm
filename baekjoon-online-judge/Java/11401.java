import java.util.Scanner;

public class Main {

	static int N, K;
	static final int P = 1000000007;
	static long[] factorial;
	static long answer = 1;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		K = sc.nextInt();

		// factorial
		factorial = new long[N + 1];
		factorial[0] = 1;
		for (int i = 1; i <= N; i++) {
			factorial[i] = (i * factorial[i - 1]) % P;
		}

		// Fermat's little theorem
		answer = (answer * factorial[N]) % P;
		answer = (answer * modPower(factorial[K], P - 2)) % P;
		answer = (answer * modPower(factorial[N - K], P - 2)) % P;

		// result
		System.out.println(answer);
		sc.close();
	}

	static long modPower(long a, long b) {
		return b == 0 ? 1 : (b % 2 == 1 ? (modPower(a, b - 1) * a) % P : modPower((a * a) % P, b / 2) % P);
	}

}
