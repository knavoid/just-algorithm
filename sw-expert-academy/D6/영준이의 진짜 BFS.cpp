#include <iostream>
#include <vector>
#include <queue>

#define N_MAX 100000
#define DEPTH_MAX 17

using namespace std;

int T, N;
int depth[N_MAX + 1];
int parent[DEPTH_MAX + 1][N_MAX + 1];
vector<vector<int>> graph;
vector<int> seq;
long long answer;

int lca(int now, int next) {
	// 깊이가 동일하도록 조정
	if (depth[now] < depth[next]) {
		next = parent[0][next];
	}
	if (now == next) {
		return now;
	}
	// 두 노드의 상위 노드가 같아지도록 조정
	for (int d = DEPTH_MAX; d >= 0; d--) {
		if (parent[d][now] != parent[d][next]) {
			now = parent[d][now];
			next = parent[d][next];
		}
	}
	return parent[0][now];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		long long answer = 0;
		// initialize
		cin >> N;
		graph.assign(N + 1, vector<int>());
		seq.clear();
		for (int i = 2; i <= N; i++) {
			cin >> parent[0][i];
			graph[parent[0][i]].push_back(i);
		}
		// BFS
		queue<pair<int, int>> q;
		q.push({ 1, 0 }); // 1번 노드 depth : 0
		while (!q.empty()) {
			int now = q.front().first;
			int dep = q.front().second;
			q.pop();
			seq.push_back(now);
			depth[now] = dep;
			for (int next : graph[now]) {
				q.push({ next, dep + 1 });
			}
		}
		// LCA
		for (int d = 1; d <= DEPTH_MAX; d++) {
			for (int n = 1; n <= N_MAX; n++) {
				parent[d][n] = parent[d - 1][parent[d - 1][n]];
			}
		}
		for (int i = 0; i < seq.size() - 1; i++) {
			int now = seq[i];
			int next = seq[i + 1];
			answer += depth[now] + depth[next] - (2 * depth[lca(now, next)]);
		}
		// result
		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}