#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {

	string rs = s; // s를 거꾸로하는 문자열
	reverse(rs.begin(), rs.end());

	return s == rs;
}

int main() {

	for (int tc = 1; tc <= 10; tc++) {
		int len; // 찾을 회문의 길이
		int answer = 0;
		string board[8];

		cin >> len;
		for (int i = 0; i < 8; i++)
			cin >> board[i];

		// 가로
		for (int i = 0; i < 8; i++) 
			for (int j = 0; j <= 8 - len; j++) 
				if (isPalindrome(board[i].substr(j, len)))
					answer++;

		// 세로
		for (int j = 0; j < 8; j++) {
			for (int i = 0; i <= 8 - len; i++) {
				string s;
				for (int k = 0; k < len; k++)
					s += board[i + k][j];
				if (isPalindrome(s))
					answer++;
			}
		}

		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}