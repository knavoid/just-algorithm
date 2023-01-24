#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, K, answer = 0;
		cin >> N >> K;

		vector<int> scores(N);
		for (int i = 0; i < N; i++)
			cin >> scores[i];

		sort(scores.begin(), scores.end(), greater<int>());

		for (int i = 0; i < K; i++)
			answer += scores[i];

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}