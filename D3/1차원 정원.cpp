#include <iostream>

using namespace std;

int main() {
	 
	int T;
	cin >> T;
	
	for (int t = 1; t <= T; t++) {
		int N, D;
		cin >> N >> D;

		cout << '#' << t << ' ' << (N - 1) / (2 * D + 1) + 1 << '\n';
	}

	return 0;
}