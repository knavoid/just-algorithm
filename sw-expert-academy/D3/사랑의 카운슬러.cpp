#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
long long answer;
vector<pair<int, int>> worms;

// 이동하는 지렁이들과 이동하지 않는 지렁이들을 선택
void selectWorms(int cnt1, int cnt2, long long x, long long y) {

	if (cnt1 + cnt2 == N) {
		answer = min(x * x + y * y, answer);
		return;
	}

	pair<int, int> w = worms[cnt1 + cnt2];
	if (cnt1 < N / 2)
		selectWorms(cnt1 + 1, cnt2, x + w.first, y + w.second);
	if (cnt2 < N / 2)
		selectWorms(cnt1, cnt2 + 1, x - w.first, y - w.second);
}

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		worms.assign(N, { 0, 0 });
		for (int i = 0; i < N; i++)
			cin >> worms[i].first >> worms[i].second;

		answer = LLONG_MAX;
		selectWorms(0, 0, 0, 0);

		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}