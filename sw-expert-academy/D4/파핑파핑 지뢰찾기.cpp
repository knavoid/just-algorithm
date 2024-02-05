#include <iostream>
#include <string>
#include <queue>

using namespace std;

int T, N, click;
string map[300];
int bombCnt[300][300];
bool visit[300][300];
int direct[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		click = 0;
		for (int i = 0; i < N; i++) {
			cin >> map[i];
		}
		fill(bombCnt[0], bombCnt[N - 1] + N, 0);
		fill(visit[0], visit[N - 1] + N, 0);
		// 지뢰 수 기록
		for (int x = 0; x < N; x++) {

			for (int y = 0; y < N; y++) {
				if (map[x][y] != '*') {
					for (int d = 0; d < 8; d++) {
						int dx = x + direct[d][0];
						int dy = y + direct[d][1];
						if (0 <= dx && dx < N && 0 <= dy && dy < N && map[dx][dy] == '*') {
							bombCnt[x][y]++;
						}
					}
				}
				else {
					bombCnt[x][y] = -1;
				}
			}
		}
		// 0 클릭하기
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (!visit[x][y] && bombCnt[x][y] == 0) {
					click++;
					queue<pair<int, int>> q;
					q.push({ x, y });
					visit[x][y] = true;
					while (!q.empty()) {
						int qx = q.front().first;
						int qy = q.front().second;
						q.pop();
						for (int d = 0; d < 8; d++) {
							int dx = qx + direct[d][0];
							int dy = qy + direct[d][1];
							if (0 <= dx && dx < N && 0 <= dy && dy < N && !visit[dx][dy]) {
								visit[dx][dy] = true;
								if (bombCnt[dx][dy] == 0) {
									q.push({ dx, dy });
								}
							}
						}
					}
				}
			}
		}
		// 0이 아닌 수 클릭하기
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (!visit[x][y] && 0 < bombCnt[x][y]) {
					click++;
				}
			}
		}
	
		cout << '#' << tc << ' ' << click << '\n';
	}

	return 0;
}