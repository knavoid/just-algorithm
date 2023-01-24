#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {

	// n x m 크기의 0으로 채워진 배열
	vector<vector<int>> map(n, vector<int>(m, 0));

	// 물웅덩이는 -1로 표시
	for (int i = 0; i < puddles.size(); i++)
	{
		int row = puddles[i][1] - 1;
		int col = puddles[i][0] - 1;
		map[row][col] = -1;
	}

	map[0][0] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] != -1)
			{
				int up = 0, left = 0;
				if (i > 0 && map[i - 1][j] != -1) up = max(up, map[i - 1][j]);
				if (j > 0 && map[i][j - 1] != -1) left = max(left, map[i][j - 1]);
				map[i][j] = max(map[i][j], up + left) % 1000000007;
			}
		}
	}

	return map[n - 1][m - 1];
}
