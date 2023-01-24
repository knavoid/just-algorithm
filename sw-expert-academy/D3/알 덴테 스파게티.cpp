#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N, B, E, sand, answer = 0;
		cin >> N >> B >> E;

		for (int i = 0; i < N; i++) {
			cin >> sand;
			for (int t = B - E; t <= B + E; t++) {
				if (t % sand == 0) {
					answer++;
					break;
				}
			}
		}

		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}