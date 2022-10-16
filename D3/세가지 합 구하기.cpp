#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		long long N;
		cin >> N;

		long long S1 = N * (N + 1) / 2;
		long long S2 = N * N;
		long long S3 = N * N + N;

		cout << '#' << t << ' ';
		cout << S1 << ' ' << S2 << ' ' << S3 << '\n';
	}

	return 0;
}