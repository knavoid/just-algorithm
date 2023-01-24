#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, A, B;
		cin >> N >> A >> B;

		int maxValue = min(A, B);
		int minValue = max(0, A + B - N);

		cout << '#' << t << ' ' << maxValue << ' ' << minValue << '\n';
	}

	return 0;
}