#include <iostream>

using namespace std;

int T, N, M;

int main() {

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		// initialize
		cin >> N >> M;

		// result
		int b = (1 << N) - 1;
		cout << '#' << tc << ' ';
		b == (b & M) ? cout << "ON\n" : cout << "OFF\n";
	}

	return 0;
}