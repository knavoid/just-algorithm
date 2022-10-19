#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int h1, m1, h2, m2;
		cin >> h1 >> m1 >> h2 >> m2;

		int H = h1 + h2;
		int M = m1 + m2;

		if (M >= 60) {
			M %= 60;
			H++;
		}

		if (H > 12)
			H -= 12;

		cout << '#' << t << ' ' << H << ' ' << M << '\n';
	}

	return 0;
}