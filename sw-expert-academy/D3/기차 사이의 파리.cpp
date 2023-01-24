#include <iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 소수점 6자리 고정
	cout << fixed;
	cout.precision(6);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		long double D, A, B, F;
		cin >> D >> A >> B >> F;

		// (기차 충돌까지 걸린 시간) * (파리 속력)
		long double answer = D / (A + B) * F;
		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}