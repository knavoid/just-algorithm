#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		long long N, A, B;
		long long answer = LLONG_MAX;
		cin >> N >> A >> B;

		for (int R = 1; R <= N; R++) {
			for (int C = 1; R * C <= N; C++) {
				long long value = A * abs(R - C) + B * (N - R * C);
				answer = min(value, answer);
			}
		}

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}