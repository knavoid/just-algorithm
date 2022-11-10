#include <iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int A, B, C, D, answer;
		cin >> A >> B >> C >> D;

		answer = max(0, min(B, D) - max(A, C));
		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}