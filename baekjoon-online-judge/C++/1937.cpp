#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int n;
int bamboo[500][500];
int dist[500][500];
multimap<int, pair<int, int>, greater<int>> point;
pair<int, int> direct[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int answer;

int main() {
	// initialize
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> bamboo[i][j];
			point.insert(make_pair(bamboo[i][j], make_pair(i, j)));
		}
	}

	// solution
	for (pair<int, pair<int, int>> p : point) {
		int x = p.second.first;
		int y = p.second.second;
		int maxValue = 0;
		for (int d = 0; d < 4; d++) {
			int dx = x + direct[d].first;
			int dy = y + direct[d].second;
			if ((0 <= dx && dx < n && 0 <= dy && dy < n) && bamboo[x][y] != bamboo[dx][dy]) {
				maxValue = max(maxValue, dist[dx][dy]);
			}
		}
		dist[x][y] = maxValue + 1;
		answer = max(answer, dist[x][y]);
	}

	// result
	cout << answer;

	return 0;
}