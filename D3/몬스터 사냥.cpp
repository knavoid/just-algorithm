#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int D, L, N, totalDamage = 0;
		cin >> D >> L >> N;

		for (int i = 0; i < N; i++)
			totalDamage += D * (100 + i * L) / 100;

		cout << '#' << t << ' ' << totalDamage << '\n';
	}

	return 0;
}