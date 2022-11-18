#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;

		vector<int> x(N + 1), y(N + 1), s(N + 1);
		for (int i = 1; i <= N; i++)
			cin >> x[i] >> y[i] >> s[i];

		// 각 마을이 서로에게 주는 영향력 표시
		vector<vector<double>> influence(N + 1, vector<double>(N + 1));
		for (int i = 1; i <= N; i++) 
			for (int j = 1; j <= N; j++)
				if (i != j)
					influence[i][j] = s[i] / (pow(x[j] - x[i], 2) + pow(y[j] - y[i], 2));

		// 각 마을이 받는 영향력들을 고려하여 체제 설정
		vector<int> answer(N + 1); // 0: 군주제, -1: 공화제, 1이상: 해당 마을 체제를 따름
		for (int j = 1; j <= N; j++) {
			double maxInf = 0; // j마을을 위협하는 마을들중 가장 큰 영향력
			int maxCnt = 0; // j마을을 위협하는 마을들중 가장 큰 영향력을 가진 마을의 수
			for (int i = 1; i <= N; i++) {
				if (influence[i][j] > s[j]) { // 영향력이 군사력보다 큰 경우
					if (influence[i][j] > maxInf) {
						answer[j] = i;
						maxInf = influence[i][j];
						maxCnt = 1;
					}
					else if (influence[i][j] == maxInf)
						maxCnt++;
				}
			}
			if (maxCnt >= 2)
				answer[j] = -1;
		}

		cout << '#' << tc << ' ';
		for (int i = 1; i <= N; i++) {
			if (answer[i] == 0)
				cout << "K ";
			else if (answer[i] == -1)
				cout << "D ";
			else {
				// 현재 따르는 마을지 군주제가 아니면, 그 마을이 따르는 마을을 따름
				while (answer[answer[i]] != 0)
					answer[i] = answer[answer[i]];
				cout << answer[i] << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}