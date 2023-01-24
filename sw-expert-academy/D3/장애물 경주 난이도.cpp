#include <iostream>
#include <vector>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, ascMax = 0, descMax = 0;
		cin >> N;

		vector<int> heights(N);
		for (int i = 0; i < N; i++)
			cin >> heights[i];

		for (int i = 0; i < N - 1; i++) {
			int difficulty = heights[i + 1] - heights[i];
			ascMax = max(ascMax, difficulty);
			descMax = min(descMax, difficulty);
		}

		cout << '#' << t << ' ' << ascMax << ' ' << -descMax << '\n';
	}

	return 0;
}