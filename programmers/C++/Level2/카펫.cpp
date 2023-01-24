#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {

	vector<int> answer;

	for (int i = 1; i <= yellow / 2 + 1; i++)
	{
		if (yellow % i != 0) continue;

		int row = yellow / i;
		int col = i;

		int border = 2 * (row + col) + 4;
		if (border == brown)
		{
			answer.push_back(row + 2);
			answer.push_back(col + 2);
			break;
		}
	}

	return answer;
}
