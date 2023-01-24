#include <iostream>

using namespace std;

int main() {
	 
	int T;
	cin >> T;
	
	for (int t = 1; t <= T; t++) {
		int N, M, answer = 0, fly[15][15];
		
		cin >> N >> M;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> fly[i][j];

		// 가능한 파리채의 위치를 모두 고려
		for (int i = 0; i < N - M + 1; i++) {
			for (int j = 0; j < N - M + 1; j++) {
				int sum = 0;
				for (int k = 0; k < M; k++)
					for (int l = 0; l < M; l++)
						sum += fly[i + k][j + l];
				answer = max(sum, answer);
			}
		}
		
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}