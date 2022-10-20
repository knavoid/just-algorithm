#include <iostream>
#include <vector>

using namespace std;

bool inRange(int N, int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;
}

void printSnail(int N) {
	
	vector<vector<int>> snail(N, vector<int>(N));
	int direct[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
	int r = 0, c = 0, dir = 0;

	// 달팽이 채우기
	snail[0][0] = 1;
	for (int v = 2; v <= N * N; v++) {
		int dr = r + direct[dir][0];
		int dc = c + direct[dir][1];
		// 진행하는 위치가 배열 범위에 속하는지 파악
		if (inRange(N, dr, dc) && snail[dr][dc] == 0) {
			r = dr, c = dc;
			snail[r][c] = v;
		}
		else {
			dir = (dir + 1) % 4;
			v--;
		}
	}

	// 달팽이 출력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << snail[i][j] << ' ';
		cout << '\n';
	}
}

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;

		cout << '#' << t << '\n';
		printSnail(N);
	}

	return 0;
}