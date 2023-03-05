#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int T; // 테스트 케이스 수
int N; // 지도 크기
int K; // 최대 공사 가능 깊이
int map[8][8]; // 지도 정보
bool isPeak[8][8]; // 봉우리 판단
int direct[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int answer; // 가장 긴 등산로 길이

bool inRange(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < N;
}

void hiking() {
	int length[8][8] = { }; // 등산로 길이 저장
	vector<pair<int, pair<int, int>>> location; // 높이 및 위치 저장
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			location.push_back(make_pair(map[i][j], make_pair(i, j)));
		}
	}
	// 높이 오름차순 정렬
	sort(location.begin(), location.end());

	for (pair<int, pair<int, int>> loc : location) {
		// 주변에서 가장 높은 높이 구하기
		int h = 0; 
		int x = loc.second.first;
		int y = loc.second.second;
		for (int d = 0; d < 4; d++) {
			int dx = x + direct[d][0];
			int dy = y + direct[d][1];
			if (inRange(dx, dy) && map[x][y] != map[dx][dy]) {
				h = max(h, length[dx][dy]);
			}
		}
		// 가장 긴 등산로 기록
		length[x][y] = h + 1;

		// 봉우리이면 정답 업데이트
		if (isPeak[x][y]) {
			answer = max(answer, length[x][y]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int maxHeight = INT_MIN;

		// initialize
		answer = 0;
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				maxHeight = max(maxHeight, map[i][j]);
			}
		}
		fill(isPeak[0], isPeak[8], false);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == maxHeight) {
					isPeak[i][j] = true; // 봉우리 표시
				}
			}
		}

		// solution
		hiking();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 1; k <= K; k++) {
					// k만큼 깎고 등산로 측정
					map[i][j] -= k;
					hiking();
					map[i][j] += k;
				}
			}
		}

		// result
		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}