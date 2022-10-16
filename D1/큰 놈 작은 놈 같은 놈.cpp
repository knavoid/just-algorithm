#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int n1, n2;
		cin >> n1 >> n2;

		char oper = n1 == n2 ? '=' : n1 > n2 ? '>' : '<';
		cout << '#' << t << ' ' << oper << '\n';
	}

	return 0;
}