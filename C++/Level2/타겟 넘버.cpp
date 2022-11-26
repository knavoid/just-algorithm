#include <string>
#include <vector>

using namespace std;

void dfs(vector<int> numbers, int target, int lev, int sum, int* count) {

	if (lev == numbers.size()) {
		if (sum == target) (*count)++;
		return;
	}

	dfs(numbers, target, lev + 1, sum + numbers[lev], count);
	dfs(numbers, target, lev + 1, sum - numbers[lev], count);
}

int solution(vector<int> numbers, int target) {

	int answer = 0;

	dfs(numbers, target, 0, 0, &answer);

	return answer;
}
