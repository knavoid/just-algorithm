#include <iostream>
#include <string>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int a = 1, b = 1;
		string str;
		cin >> str;

		for (char c : str) {
			if (c == 'L')
				b += a;
			else  // c == 'R'
				a += b;
		}

		cout << '#' << t << ' ' << a << ' ' << b << '\n';
	}

	return 0;
}