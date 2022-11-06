#include <iostream>
using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int a, b, c;
		cin >> a >> b >> c;

		cout << '#' << t << ' ';
		a == b ? cout << c : a == c ? cout << b : cout << a;
		cout << '\n';
	}

	return 0;
}