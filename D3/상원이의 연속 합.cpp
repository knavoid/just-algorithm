#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N, answer = 0;
		cin >> N;

		// p1 <= p2
		// sum: p1 이상 p2 미만의 자연수를 더한 값
		int p1 = 1, p2 = 2, sum = 1;
		while (p1 <= N) {
			if (sum < N) {
				sum += p2;
				p2++;
			}
			else {
				if (sum == N)
					answer++;
				sum -= p1;
				p1++;
			}
		}
		
		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}