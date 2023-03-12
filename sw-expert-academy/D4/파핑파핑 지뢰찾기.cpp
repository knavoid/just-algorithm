#include <iostream>
#include <string>
#include <queue>

using namespace std;

int T;
int N; // 지뢰 찾기 표 크기
string landmine[300]; // 지뢰 정보
int direct[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
int answer; // 최소 클릭 횟수

bool inRange(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < N;
}

// 해당 칸의 주변 지뢰 개수 반환
int landmineCount(int x, int y) {
	int count = 0;
	for (int d = 0; d < 8; d++) {
		int dx = x + direct[d][0];
		int dy = y + direct[d][1];
		if (inRange(dx, dy) && landmine[dx][dy] == '*') {
			count++;
		}
	}
	return count;
}

void click(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	landmine[x][y] = '0';
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int d = 0; d < 8; d++) {
			int dx = x + direct[d][0];
			int dy = y + direct[d][1];
			if (inRange(dx, dy) && landmine[dx][dy] == '.') {
				int count = landmineCount(dx, dy);
				landmine[dx][dy] = count + '0';
				if (count == 0) {
					q.push(make_pair(dx, dy));
				}
			}
		}
	}
	answer++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		// initialize
		answer = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> landmine[i];
		}

		// 0을 찾아서 클릭
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (landmine[x][y] == '.' && landmineCount(x, y) == 0) {
					click(x, y);
				}
			}
		}

		// 0이 아닌 다른 수 클릭
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (landmine[x][y] == '.') {
					answer++;
				}
			}
		}

		// result
		cout << '#' << tc << ' ' << answer << '\n';
	}
	

	return 0;
}