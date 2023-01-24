#include <iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		long double A, B, C, D;
		cin >> A >> B >> C >> D;

		long double alice = A / B;
		long double bob = C / D;

		cout << '#' << tc << ' ';
		if (alice > bob)
			cout << "ALICE\n";
		else if (alice < bob)
			cout << "BOB\n";
		else
			cout << "DRAW\n";
	}

	return 0;
}