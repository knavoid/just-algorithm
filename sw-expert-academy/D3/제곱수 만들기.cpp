#include <iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int A;
		cin >> A;

		int n = 2;
		while (n * n <= A) {
			int sq = n * n;
			if (A % sq == 0)
				A /= sq;
			else
				n++;
		}

		cout << '#' << tc << ' ' << A << '\n';
	}

	return 0;
}