#include <iostream>
#include <string>
#include <vector>

using namespace std;

string Omok(int N, vector<string> board) {
	// 가로 판단
	for (int i = 0; i < N; i++)
		if (board[i].find("ooooo") != string::npos)
			return "YES";

	// 세로 판단
	for (int j = 0; j < N; j++) {
		string str;
		for (int i = 0; i < N; i++)
			str += board[i][j];
		if (str.find("ooooo") != string::npos)
			return "YES";
	}

	// 대각선 판단
	for (int i = 0; i <= N - 5; i++) {
		for (int j = 0; j <= N - 5; j++) {
			bool omok = true;
			for (int k = 0; k < 5; k++) {
				if (board[i + k][j + k] == '.') {
					omok = false;
					break;
				}
			}
			if (omok)
				return "YES";
		}
	}
	for (int i = 4; i < N; i++) {
		for (int j = 0; j <= N - 5; j++) {
			bool omok = true;
			for (int k = 0; k < 5; k++) {
				if (board[i - k][j + k] == '.') {
					omok = false;
					break;
				}
			}
			if (omok)
				return "YES";
		}
	}


	return "NO";
}

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;

		vector<string> board(N);
		for (int i = 0; i < N; i++)
			cin >> board[i];

		string answer = Omok(N, board);
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}