#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int n, m;
		cin >> n >> m;

		int u = 2 * m - n;	// 유니콘의 수
		int t = n - m;		// 트윈혼의 수

		cout << '#' << tc << ' ' << u << ' ' << t << '\n';
	}

	return 0;
}