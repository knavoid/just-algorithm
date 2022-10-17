#include <iostream>
#include <vector>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, K;
		cin >> N >> K;

		vector<bool> assignment(N);
		for (int i = 0; i < K; i++) {
			int number;
			cin >> number;
			assignment[number - 1] = true;
		}

		cout << '#' << t << ' ';
		for (int i = 0; i < N; i++)
			if (!assignment[i])
				cout << i + 1 << ' ';
		cout << '\n';
	}

	return 0;
}