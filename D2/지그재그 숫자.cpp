#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, answer = 0;
		cin >> N;
		for (int i = 1; i <= N; i++)
			answer += i % 2 ? i : -i;

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}