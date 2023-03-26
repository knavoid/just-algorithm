#include <iostream>

using namespace std;

int T, n;
int answer[12] = { 0, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274, 504 };

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		cout << answer[n] << '\n';
	}

	return 0;
}