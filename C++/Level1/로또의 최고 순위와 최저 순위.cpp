#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int getRank(int count) {
	return min(6, 7 - count);
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	int match = 0;
	int invalid = 0;
	unordered_set<int> set(win_nums.begin(), win_nums.end());

	for (int lotto : lottos) {
		if (lotto == 0)
			invalid++;
		else if (set.find(lotto) != set.end())
			match++;
	}

	return vector<int>{getRank(match + invalid), getRank(match)};
}