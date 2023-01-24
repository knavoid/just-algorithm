#include <iostream>
#include <vector>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, K, len, answer = 0;
		cin >> N >> K;

		vector<vector<int>> puzzle(N, vector<int>(N));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> puzzle[i][j];

		// 가로 퍼즐 
		for (int i = 0; i < N; i++) {
			len = 0;
			for (int j = 0; j < N; j++) {
				if (puzzle[i][j] == 1)
					len++;
				if (puzzle[i][j] == 0 || j == N - 1) {
					if (len == K)
						answer++;
					len = 0;
				}
			}
		}

		// 세로 퍼즐 
		for (int j = 0; j < N; j++) {
			len = 0;
			for (int i = 0; i < N; i++) {
				if (puzzle[i][j] == 1)
					len++;
				if (puzzle[i][j] == 0 || i == N - 1) {
					if (len == K)
						answer++;
					len = 0;
				}
			}
		}

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}