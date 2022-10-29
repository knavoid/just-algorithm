#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		long L;
		cin >> L;

		cout << '#' << t << ' ' << (L / 2) * (L / 2) << '\n';
	}

	return 0;
}