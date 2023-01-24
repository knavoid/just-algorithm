#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums) {

	int select = nums.size() / 2;
	map<int, bool> kind;

	for (int num : nums) {
		kind.insert({ num, 1 });
	}

	return min((int)kind.size(), select);
}
