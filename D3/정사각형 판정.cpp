#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N;
		string answer = "yes";
		cin >> N;

		vector<string> grid(N);
		for (int i = 0; i < N; i++)
			cin >> grid[i];

		// 막혀 있는 칸들의 행번호, 열번호 최댓값과 최솟값
		int maxX = 0, minX = N;
		int maxY = 0, minY = N;

		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (grid[x][y] == '#') {
					maxX = max(x, maxX);
					minX = min(x, minX);
					maxY = max(y, maxY);
					minY = min(y, minY);
				}
			}
		}

		// 가로 세로 범위가 같지 않은 경우
		if (maxX - minX != maxY - minY)
			answer = "no";
		else 
			for (int x = 0; x < N; x++) 
				for (int y = 0; y < N; y++) 
					// 범위 안에 있는데 #이 아니거나, 범위 밖인데 #인 경우 "no"로 변경
					if ((grid[x][y] == '#') ^ (minX <= x && x <= maxX && minY <= y && y <= maxY))
						answer = "no";

		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}