#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, M;
		map<int, int> cardCount;

		cin >> N >> M;

		for (int n = 1; n <= N; n++)
			for (int m = 1; m <= M; m++)
				cardCount[n + m]++;

		int maxCount = max_element(cardCount.begin(), cardCount.end(),
			[](auto& x, auto& y) { return x.second < y.second; })->second;
		
		cout << '#' << t << ' ';
		for (auto p : cardCount)
			if (p.second == maxCount)
				cout << p.first << ' ';

		cout << '\n';
	}

	return 0;
}