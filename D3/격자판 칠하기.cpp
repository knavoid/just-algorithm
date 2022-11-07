#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N, M;
		string answer = "possible";
		cin >> N >> M;

		vector<string> grid(N);
		for (int i = 0; i < N; i++)
			cin >> grid[i];

		// 각 타일색의 행번호와 열번호의 합을 2로 나눈 나머지를 저장
		vector<int> black, white;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (grid[i][j] == '#')
					black.push_back((i + j) % 2);
				if (grid[i][j] == '.')
					white.push_back((i + j) % 2);
			}
		}

		// black, white에 저장된 값들이 모두 1 또는 모두 0으로 저장되었는지 확인
		if (!black.empty() && !white.empty()) {
			int b1 = black.front();
			int w1 = white.front();
			if (b1 == w1)
				answer = "impossible";
			else if (count(black.begin(), black.end(), w1) || count(white.begin(), white.end(), b1))
				answer = "impossible";
		}
		else if (black.empty()) {
			if (count(white.begin(), white.end(), white.front()) != white.size())
				answer = "impossible";
		}
		else if (white.empty()) {
			if (count(black.begin(), black.end(), black.front()) != black.size())
				answer = "impossible";
		}


		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}