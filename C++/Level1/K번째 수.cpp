#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {

	vector<int> answer;

	for (int x = 0; x < commands.size(); x++)
	{
		int i = commands[x][0];
		int j = commands[x][1];
		int k = commands[x][2];

		vector<int> vect;
		for (int y = i - 1; y < j; y++) vect.push_back(array[y]);
		sort(vect.begin(), vect.end());

		int value = vect[k - 1];
		answer.push_back(value);
	}

	return answer;
}