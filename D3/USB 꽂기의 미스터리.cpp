#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		double p, q;
		cin >> p >> q;

		// (올바르지 않은 면) - (올바른 면)
		double s1 = (1 - p) * q;
		// (올바른 면) - (올바르지 않은 면) - (올바른 면)
		double s2 = p * (1 - q) * q;

		cout << '#' << tc << ' ';
		s1 < s2 ? cout << "YES\n" : cout << "NO\n";
	}

	return 0;
}