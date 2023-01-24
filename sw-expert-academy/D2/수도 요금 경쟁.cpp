#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int P, Q, R, S, W;
		cin >> P >> Q >> R >> S >> W;

		int feeA = P * W;
		int feeB = W <= R ? Q : Q + S * (W - R);


		cout << '#' << t << ' ' << min(feeA, feeB) << '\n';
	}

	return 0;
}