#include <iostream>
#include <vector>

using namespace std;

int N;
int answer;

void NQueens(int x, vector<pair<int, int>> points) {

	if (x == N) {
		answer++;
		return;
	}

	for (int y = 0; y < N; y++) {
		bool possible = true;
		for (pair<int, int> p : points) {
			// 같은 행, 같은 열, 같은 대각선 상에 있는 경우 제외
			if (p.first == x || p.second == y || abs(x - p.first) == abs(y - p.second)) {
				possible = false;
				break;
			}
		}
		if (possible) {
			points.push_back(make_pair(x, y));
			NQueens(x + 1, points);
			points.pop_back();
		}
	}
}

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N;

		answer = 0;
		NQueens(0, { });

		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}