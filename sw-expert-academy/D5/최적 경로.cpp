#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int T, N, answer;
int cx, cy, hx, hy, dist;
vector<pair<int, int>> p;

int main() {

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		// input
		cin >> N >> cx >> cy >> hx >> hy;
		p.assign(N, { 0, 0 });
		for (int i = 0; i < N; i++)
			cin >> p[i].first >> p[i].second;

		// solution
		answer = INT_MAX;
		sort(p.begin(), p.end());
		do {
			dist = 0;

			// 회사 -> 첫번째 고객
			dist += abs(cx - p.front().first) + abs(cy - p.front().second);

			// 각 고객들 거리
			for (int i = 0; i < p.size() - 1; i++)
				dist += abs(p[i].first - p[i + 1].first) + abs(p[i].second - p[i + 1].second);

			// 마지막 고객 -> 집
			dist += abs(p.back().first - hx) + abs(p.back().second - hy);

			answer = min(dist, answer);
		} while (next_permutation(p.begin(), p.end()));

		// output
		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}