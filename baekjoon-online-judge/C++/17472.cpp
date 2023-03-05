#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int N, M;
int info[10][10]; // 입력한 지도 정보
int map[10][10]; // 섬의 번호가 적힌 지도 정보
pair<int, int> direct[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
vector<vector<int>> minDist; // 각 섬간의 최소 거리

bool inRange(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < M;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// initialzie
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> info[i][j];
		}
	}

	// 각 섬에 번호 붙이기
	int n = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (info[i][j] == 1) {
				queue<pair<int, int>> q;
				info[i][j] = 0;
				map[i][j] = n;
				q.push(make_pair(i, j));
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int d = 0; d < 4; d++) {
						int dx = x + direct[d].first;
						int dy = y + direct[d].second;
						if (inRange(dx, dy) && info[dx][dy] == 1) {
							info[dx][dy] = 0;
							map[dx][dy] = n;
							q.push(make_pair(dx, dy));
						}
					}
				}
				n++;
			}
		}
	}

	// 각 섬의 가장자리에서 연결 가능한 섬 찾기
	minDist.assign(n, vector<int>(n, INT_MAX));
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			if (map[x][y] != 0) { // 섬
				int from = map[x][y]; // 출발하는 섬의 번호
				for (int d = 0; d < 4; d++) {
					int dist = 0; // 놓을 수 있는 다리 길이
					int dx = x + direct[d].first;
					int dy = y + direct[d].second;
					while (inRange(dx, dy) && map[dx][dy] == 0) { // 가장자리에서 출발
						dist++;
						dx += direct[d].first;
						dy += direct[d].second;
					}
					if (dist >= 2 && inRange(dx, dy)) {
						int to = map[dx][dy]; // 도착하는 섬의 번호
						minDist[from][to] = min(minDist[from][to], dist);
					}
				}
			}
		}
	}

	// MST (Prim)
	int answer = 0;
	vector<bool> visited(n, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 거리가 짧으면 우선순위 높음
	pq.push(make_pair(0, 1)); // 1번 섬에서 출발 
	while (!pq.empty()) {
		int dist = pq.top().first;
		int curr = pq.top().second;
		pq.pop();
		if (visited[curr]) {
			continue;
		}
		visited[curr] = true;
		answer += dist;

		// 현재 섬에서 갈 수 있는 섬을 추가
		for (int next = 1; next < n; next++) {
			if (!visited[next] && minDist[curr][next] != INT_MAX) {
				pq.push(make_pair(minDist[curr][next], next));
			}
		}
	}

	// result
	all_of(visited.begin() + 1, visited.end(), [](bool b) { return b; }) ? cout << answer : cout << -1;

	return 0;
}