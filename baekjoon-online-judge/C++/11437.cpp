#include <iostream>
#include <vector>

#define N_MAX 100000
#define DEPTH_MAX 17

using namespace std;

int N, M;
int depth[N_MAX + 1];
int parent[DEPTH_MAX + 1][N_MAX + 1];
bool visit[N_MAX + 1];
vector<int> graph[N_MAX + 1];

void dfs(int now, int dep) {
	depth[now] = dep;
	for (int next : graph[now]) {
		if (!visit[next]) {
			visit[next] = true;
			parent[0][next] = now;
			dfs(next, dep + 1);
		}
	}
}

int lca(int v1, int v2) {
	// depth[v1] >= depth[v2] 이도록 설정
	if (depth[v1] < depth[v2]) {
		swap(v1, v2);
	}
	// 깊이가 동일하도록 조정
	for (int d = DEPTH_MAX - 1; d >= 0; d--) {
		if ((1 << d) <= depth[v1] - depth[v2]) {
			v1 = parent[d][v1];
		}
	}
	if (v1 == v2) {
		return v1;
	}
	// 두 노드의 상위 노드가 같아지도록 조정
	for (int d = DEPTH_MAX - 1; d >= 0; d--) {
		if (parent[d][v1] != parent[d][v2]) {
			v1 = parent[d][v1];
			v2 = parent[d][v2];
		}
	}
	return parent[0][v1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// initialize
	int v1, v2;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	
	// dfs
	visit[1] = true;
	dfs(1, 0);

	// lca
	for (int d = 1; d <= DEPTH_MAX; d++) {
		for (int n = 1; n <= N; n++) {
			parent[d][n] = parent[d - 1][parent[d - 1][n]];
		}
	}

	// result
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2;
		cout << lca(v1, v2) << '\n';
	}

	return 0;
}