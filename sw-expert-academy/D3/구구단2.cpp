#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int A, B;
		cin >> A >> B;

		cout << '#' << t << ' ';
		if (0 <= A && A < 10 && 0 <= B && B < 10)
			cout << A * B << '\n';
		else
			cout << -1 << '\n';
	}

	return 0;
}