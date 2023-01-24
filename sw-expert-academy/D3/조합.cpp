#include <iostream>

#define M 1234567891

using namespace std;

// a^b 계산 함수
long long modPower(long long a, long long b) {
	return b == 0 ? 1 : (b % 2 ? (modPower(a, b - 1) * a) % M : modPower((a * a) % M, b / 2) % M);
}


int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		long long N, R;
		cin >> N >> R;

		// R을 N/2 보다 작게 설정
		if (N < 2 * R)
			R = N - R;
		
		long long p = 1; // N!/(N-R)!
		for (long long n = N; n >= N - R + 1; n--)
			p = (p * n) % M;
		
		long long q = 1; // R!
		for (long long r = R; r > 1; r--)
			q = (q * r) % M;
		
		// 페르마의 소정리 : qi = q^(-1) mod M = q^(M-2) mod M
		long long qi = modPower(q, M - 2);

		long long answer = (p * qi) % M;
		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}