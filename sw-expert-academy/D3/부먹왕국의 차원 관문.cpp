#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int answer = 0, cnt = 0;
		int N, D, door;
		cin >> N >> D;

		for (int i = 0; i < N; i++) {
			cin >> door;
			if (door == 0)
				cnt++;
			if (door == 1 || i == N - 1) {
				answer += cnt / D;
				cnt = 0;
			}
		}

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}