#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int A, B, C;
		cin >> A >> B >> C;

		cout << '#' << t << ' ';
		A < B ? cout << C / A : cout << C / B;
		cout << '\n';
	}

	return 0;
}