#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board) {

	int max_len = 0;

	// board : x * y 배열
	int x = board.size();
	int y = board[0].size();

	// 해당 위치까지 만들 수 있는 정사각형의 최대 길이를 저장하는 배열
	vector<vector<int>> result(board.size(), vector<int>(board[0].size(), 0));

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			if (i == 0 || j == 0) result[i][j] = board[i][j];
			else if (board[i][j] == 1) result[i][j] = min({ result[i - 1][j - 1], result[i - 1][j], result[i][j - 1] }) + 1;
			max_len = max(max_len, result[i][j]);
		}
	}

	return max_len * max_len;
}
