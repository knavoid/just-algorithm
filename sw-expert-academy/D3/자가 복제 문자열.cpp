#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int answer = 0;
		long long K;
		cin >> K;

		while (K > 1) {
			long long len = 1;
			while (len < K) 
				len += len + 1;

			// K번째 수가 문자열의 중앙에 위치하는 경우
			if (K == len / 2 + 1) 
				break;

			K = len - K + 1;
			answer ^= 1; // 0 -> 1 또는 1 -> 0
		}

		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}