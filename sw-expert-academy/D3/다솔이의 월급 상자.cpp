#include <iostream>

using namespace std;

int main() {

	int TC;
	cin >> TC;

	for (int t = 1; t <= TC; t++) {
		int N;
		double p, x;
		double answer = 0;
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> p >> x;
			answer += p * x;
		}

		cout << fixed;
		cout.precision(6);
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}