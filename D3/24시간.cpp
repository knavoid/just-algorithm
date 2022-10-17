#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int A, B;
		cin >> A >> B;

		cout << '#' << t << ' ' << (A + B) % 24 << '\n';
	}

	return 0;
}