#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		string answer = "yes";
		string chessBoard[8]; // 입력 체스판
		bool visitedColumn[8] = { }; // 각 열의 방문 여부

		for (int i = 0; i < 8; i++)
			cin >> chessBoard[i];

		for (int i = 0; i < 8; i++) {
			// i행에서의 룩의 개수 파악
			int rookCount = count(chessBoard[i].begin(), chessBoard[i].end(), 'O');
			if (rookCount != 1) {
				answer = "no";
				break;
			}

			// 룩이 위치한 열 확인
			int col = chessBoard[i].find("O");
			if (visitedColumn[col]) {
				answer = "no";
				break;
			}
			visitedColumn[col] = true;
		}

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}