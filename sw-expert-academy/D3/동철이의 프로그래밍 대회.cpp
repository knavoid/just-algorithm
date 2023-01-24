#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, M;
		cin >> N >> M;

		vector<vector<int>> a(N, vector<int>(M));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cin >> a[i][j];
		
		// 점수 계산
		vector<int> score(N);
		for (int i = 0; i < N; i++)
			score[i] = count(a[i].begin(), a[i].end(), 1);

		// 가장 높은 점수와 높은 점수를 가진 사람의 수
		int maxScore = *max_element(score.begin(), score.end());
		int maxScoreCnt = count(score.begin(), score.end(), maxScore);

		cout << '#' << t << ' ' << maxScoreCnt << ' ' << maxScore << '\n';
	}

	return 0;
}