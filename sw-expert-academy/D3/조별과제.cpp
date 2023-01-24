#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;

		cout << '#' << t << ' ' << N / 3 << '\n';
	}

	return 0;
}