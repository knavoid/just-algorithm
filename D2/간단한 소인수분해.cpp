#include <iostream>

using namespace std;

int main() {

	int T;
	int prime[5] = { 2, 3, 5, 7, 11 };
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;

		cout << '#' << t << ' ';

		for (int i = 0; i < 5; i++) {
			int cnt = 0;
			int p = prime[i];
			
			while (N % p == 0) {
				cnt++;
				N /= p;
			}

			cout << cnt << ' ';
		}

		cout << '\n';
	}

	return 0;
}