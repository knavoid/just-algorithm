#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int L, U, X, answer;
		cin >> L >> U >> X;

		if (X < L)
			answer = L - X;
		else if (U < X)
			answer = -1;
		else
			answer = 0;

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}