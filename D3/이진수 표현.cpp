#include <iostream>
#include <string>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		string answer = "ON";
		int N, M;
		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			if (M % 2 == 0) {
				answer = "OFF";
				break;
			}
			M /= 2;
		}

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}