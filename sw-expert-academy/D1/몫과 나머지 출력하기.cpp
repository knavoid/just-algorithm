#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int a, b;
		cin >> a >> b;

		cout << '#' << t << ' ' << a / b << ' ' << a % b << '\n';
	}

	return 0;
}