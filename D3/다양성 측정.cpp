#include <iostream>
#include <set>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int X;
		set<int> numbers;
		cin >> X;

		while (X) {
			numbers.insert(X % 10);
			X /= 10;
		}

		cout << '#' << t << ' ' << numbers.size() << '\n';
	}

	return 0;
}