#include <iostream>
#include <vector>

#define MAX 8

using namespace std;

int N, M;
int board[MAX + 1][MAX + 1];
int direct[8][2] = {
	{-1, -1}, {-1,  0}, {-1,  1},
	{ 0, -1},			{ 0,  1},
	{ 1, -1}, { 1,  0}, { 1,  1}
};

bool inRange(int x, int y) {
	return 1 <= x && x <= N && 1 <= y && y <= N;
}

void initialize() {
	// 보드 초기화
	fill(board[0], board[MAX] + MAX + 1, 0);

	// 게임 시작 배치
	int h = N / 2;
	board[h][h] = 2;
	board[h][h + 1] = 1;
	board[h + 1][h] = 1;
	board[h + 1][h + 1] = 2;
}

void othelloGame() {
	
	int x, y, s;
	
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> s;
			
		// 돌 놓기
		board[x][y] = s;
			
		// 돌 놓은 후 업데이트
		for (int d = 0; d < 8; d++) {
			int dx = x + direct[d][0];
			int dy = y + direct[d][1];
			if (!inRange(dx, dy))
				continue;
			if (board[dx][dy] == 0)
				continue;

			vector<pair<int, int>> points;
			if (board[dx][dy] != s) {
				points.push_back({ dx, dy });
				while (1) {
					dx += direct[d][0];
					dy += direct[d][1];
					if (!inRange(dx, dy))
						break;
					if (board[dx][dy] == 0)
						break;
					if (board[dx][dy] == s) {
						for (pair<int, int> p : points)
							board[p.first][p.second] = s;
						break;
					}
					points.push_back({ dx, dy });
				}
			}
		}
	}
}

void getGameResult(int t) {

	int black = 0, white = 0;
	
	// 돌 개수 세기
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (board[i][j] == 1)
				black++;
			if (board[i][j] == 2)
				white++;
		}
	}

	// 결과 출력
	cout << '#' << t << ' ' << black << ' ' << white << '\n';
}

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M;

		initialize();
		othelloGame();
		getGameResult(t);
	}

	return 0;
}