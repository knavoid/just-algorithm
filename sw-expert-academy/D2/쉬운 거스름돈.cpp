#include <iostream>

using namespace std;

int main() {

	int T, money[8] = { 50000, 10000, 5000, 1000, 500, 100, 50, 10 };
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;

		cout << '#' << t << '\n';

		for (int i = 0; i < 8; i++) {
			cout << N / money[i] << ' ';
			N %= money[i];
		}
		cout << '\n';
	}

	return 0;
}