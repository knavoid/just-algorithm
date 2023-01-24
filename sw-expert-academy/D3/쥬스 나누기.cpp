#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int p = 1, q;
		cin >> q;

		cout << '#' << tc << ' ';
		for (int i = 0; i < q; i++)
			 cout << p << '/' << q << ' ';
		cout << '\n';
	}

	return 0;
}