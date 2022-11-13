#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string s) {

	string rs = s;
	reverse(rs.begin(), rs.end());

	return s == rs;
}

int main() {

	for (int tc = 1; tc <= 10; tc++) {
		cin >> tc;

		int answer = 1;
		string board[100];
		for (int i = 0; i < 100; i++)
			cin >> board[i];

		for (int len = 100; len >= 1; len--) {
			if (len <= answer)
				break;

			// 가로
			for (int i = 0; i < 100; i++) {
				if (len <= answer)
					break;
				for (int j = 0; j <= 100 - len; j++) {
					if (isPalindrome(board[i].substr(j, len))) {
						answer = len;
						break;
					}
				}
			}

			// 세로
			for (int j = 0; j < 100; j++) {
				if (len <= answer)
					break;
				for (int i = 0; i <= 100 - len; i++) {
					string s;
					for (int k = 0; k < len; k++)
						s += board[i + k][j];
					if (isPalindrome(s)) {
						answer = len;
						break;
					}
				}
			}
		}

		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}