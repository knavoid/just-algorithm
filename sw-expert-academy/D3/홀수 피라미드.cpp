#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		long long N;
		cin >> N;

		long long left = 2 * N * N - 4 * N + 3;
		long long right = 2 * N * N - 1;

		cout << '#' << tc << ' ' << left << ' ' << right << '\n';
	}

	return 0;
}