#include <iostream>

using namespace std;

int N;
int space[17][17];
int answer;

bool inRange(int x, int y) {
	return 1 <= x && x <= N && 1 <= y && y <= N;
}

// (x, y)에 이어서 파이프 설치
// d는 최근 파이프의 방향 (0:가로, 1:세로, 2:대각선)
void pipe(int x, int y, int d) {
	// 파이프 설치가 완료된 경우
	if (x == N && y == N) {
		answer++;
		return;
	}
	// 가로, 세로, 대각선에 대해서 비어있는지 확인
	bool b1 = inRange(x, y + 1) && !space[x][y + 1];
	bool b2 = inRange(x + 1, y) && !space[x + 1][y];
	bool b3 = inRange(x + 1, y + 1) && !space[x + 1][y + 1];

	// 이전 파이프 상태에 따른 파이프 설치
	if ((d == 0 || d == 2) && b1) { // 가로
		pipe(x, y + 1, 0);
	}
	if ((d == 1 || d == 2) && b2) { // 세로
		pipe(x + 1, y, 1);
	}
	if (b1 && b2 && b3) { // 대각선
		pipe(x + 1, y + 1, 2);
	}
}

int main() {
	// initialize
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> space[i][j];
		}
	}

	// solution
	pipe(1, 2, 0);

	// result
	cout << answer;

	return 0;
}