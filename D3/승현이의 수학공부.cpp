#include <iostream>
#include <string>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N, answer = 0;
		string X;
		cin >> N >> X;

		// X의 각 자리수 더하기
		for (char c : X)
			answer += (c - '0');

		cout << '#' << tc << ' ' << answer % (N - 1) << '\n';
	}

	return 0;
}