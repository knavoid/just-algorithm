#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int S, E, M;
		cin >> S >> E >> M;

		while (S != E || S != M) {
			if (S < E && S < M) // S가 가장 작은 경우
				S += 365;
			else if (E < M) // E가 가장 작은 경우
				E += 24;
			else // M이 가장 작은 경우
				M += 29;
		}

		cout << '#' << t << ' ' << S << '\n';
	}

	return 0;
}