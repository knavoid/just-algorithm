#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer;
pair<int, int> direct[9] = { {0, 0}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1} };

bool inRange(int x, int y) {
	return 0 <= x && x < 4 && 0 <= y && y < 4;
}

void shark(int sum, vector<vector<pair<int, int>>> fish, vector<pair<int, int>> position) {
	answer = max(answer, sum);

	// 물고기 이동
	for (int n = 1; n <= 16; n++) {
		int x = position[n].first;
		int y = position[n].second;
		// 이미 먹힌 물고기
		if (x == -1 || y == -1) {
			continue;
		}

		while (true) {
			int d = fish[x][y].second;
			int dx = x + direct[d].first;
			int dy = y + direct[d].second;
			// 이동 가능한 경우
			if (inRange(dx, dy) && fish[dx][dy].first != 0) {
				position[n] = make_pair(dx, dy);
				if (position[fish[dx][dy].first] != make_pair(-1, -1)) {
					position[fish[dx][dy].first] = make_pair(x, y);
				}
				swap(fish[x][y], fish[dx][dy]);
				break;
			}
			// 이동이 불가능하면 방향 전환
			fish[x][y].second = d % 8 + 1;
		}

	}

	// 상어 이동
	int shx = position[0].first;
	int shy = position[0].second;
	int shdir = fish[shx][shy].second;
	int degree = 1;
	while (true) {
		int dx = shx + degree * direct[shdir].first;
		int dy = shy + degree * direct[shdir].second;
		if (!inRange(dx, dy)) {
			break;
		}
		// 정보 복사
		vector<vector<pair<int, int>>> fish_ = fish;
		vector<pair<int, int>> position_ = position;

		// 상어에게 먹힘
		int num = fish_[dx][dy].first;
		if (position_[num] != make_pair(-1, -1)) {
			position_[0] = position_[num];
			position_[num] = make_pair(-1, -1); 
			fish_[dx][dy].first = 0;
			fish_[shx][shy] = make_pair(num, 0);
			shark(sum + num, fish_, position_);
		}
		degree++;
	}
}

int main() {
	vector<vector<pair<int, int>>> fish(4, vector<pair<int, int>>(4, pair<int, int>()));
	vector<pair<int, int>> position(17, pair<int, int>());

	// initialize
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> fish[i][j].first >> fish[i][j].second;
			position[fish[i][j].first] = make_pair(i, j);
		}
	}

	// solution
	int value = fish[0][0].first;
	fish[0][0] = make_pair(0, fish[0][0].second); // 상어 : 0
	position[value] = make_pair(-1, -1);
	shark(value, fish, position);

	// result
	cout << answer;

	return 0;
}