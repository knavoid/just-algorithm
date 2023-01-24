#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, answer;
vector<bool> visit;
vector<vector<bool>> path;

void graphSearch(int i, int len) {

	// 최장 경로 길이 업데이트
	answer = max(len, answer);

	visit[i] = true;
	for (int j = 1; j <= N; j++) 
		// 경로가 존재하고, 방문 이력이 없으면 탐색
		if (path[i][j] && !visit[j]) 
			graphSearch(j, len + 1);
	visit[i] = false;
}

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M;

		// 초기화
		answer = 0;
		visit.assign(N + 1, false);
		path.assign(N + 1, vector<bool>(N + 1, false));

		// 간선을 인접행렬 mat에 표시
		for (int i = 0; i < M; i++) {
			int x, y;
			cin >> x >> y;
			path[x][y] = true;
			path[y][x] = true;
		}

		// 각각의 정점에서 그래프 탐색
		for (int i = 1; i <= N; i++)
			graphSearch(i, 1);

		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}