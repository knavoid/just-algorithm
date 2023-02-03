#include <iostream>
#include <queue>
#include <climits>
#include <tuple>

using namespace std;

struct position { // 위치 정보
	int dist;
	int x, y;
	bool operator<(const position &p) const {
		return make_tuple(dist, x, y) < make_tuple(p.dist, p.x, p.y);
	}
};

int N;
int shx, shy; // 상어의 현재 위치
int fishCnt; // 먹은 물고기 수
int shSize = 2; // 상어의 현재 크기
int space[20][20]; // 공간 상태
pair<int, int> direct[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int answer;

bool inRange(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < N;
}

int main() {
	// intialize
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> space[i][j];
			if (space[i][j] == 9) {
				space[i][j] = 0;
				shx = i;
				shy = j;
			}
		}
	}

	// solution
	while (true) {
		queue<position> q;
		bool visited[20][20] = {};
		bool edible = false;
		position target = { INT_MAX, INT_MAX, INT_MAX };

		q.push({ 0, shx, shy });
		visited[shx][shy] = true;

		while (!q.empty()) {
			position now = q.front();
			q.pop();

			// now가 현재까지의 타겟보다 우선순위인 물고기인 경우
			if (space[now.x][now.y] != 0 && space[now.x][now.y] < shSize && now < target) {
				edible = true;
				target = now;
			}

			// 4방향으로 방문하면서 탐색
			for (int dir = 0; dir < 4; dir++) {
				int dx = now.x + direct[dir].first;
				int dy = now.y + direct[dir].second;
				if (inRange(dx, dy) && !visited[dx][dy] && space[dx][dy] <= shSize) {
					visited[dx][dy] = true;
					q.push({ now.dist + 1, dx, dy });
				}
			}
		}

		// 먹을 수 있는 물고기가 없는 경우
		if (!edible) {
			break;
		}

		// 물고기 잡아먹기
		answer += target.dist;
		shx = target.x;
		shy = target.y;
		space[shx][shy] = 0;
		fishCnt++;
		if (fishCnt == shSize) {
			fishCnt = 0;
			shSize++;
		}
	}

	// result
	cout << answer;

	return 0;
}