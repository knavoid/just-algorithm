#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {

	int answer = 0;

	// results 배열을 나타내기 위한 그래프 인접행렬
	vector<vector<int>> win_lose(n + 1, vector<int>(n + 1));

	// 승패 결과를 인접행렬로 표현  --  a가 b를 이긴경우 : win_lose[a][b] = 1
	for (vector<int> result : results) {
		win_lose[result[0]][result[1]] = 1;
	}

	// floyd warshall
	for (int k = 1; k <= n; k++) { // k : 거쳐가는 노드
		for (int i = 1; i <= n; i++) { // i : 출발 노드
			for (int j = 1; j <= n; j++) { // j : 도착 노드
				// i가 k를 이기고 k가 j를 이기는 경우, i가 j를 이긴다.
				if (win_lose[i][k] && win_lose[k][j]) {
					win_lose[i][j] = 1;
				}
			}
		}
	}

	// 순위가 확실한 사람 찾기
	for (int i = 1; i <= n; i++) {
		int confirmed = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (win_lose[i][j] || win_lose[j][i]) {  // 승패가 확실한 경우
				confirmed++;
			}
		}
		// 자신를 제외한 n-1명의 상대들과 승패가 확정된 경우
		if (confirmed == n - 1) {  
			answer++;
		}
	}

	return answer;
}
