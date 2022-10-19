#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;

		cout << '#' << t << ' ';
		N % 2 ? cout << "Bob" : cout << "Alice";
		cout << '\n';
	}

	return 0;
}