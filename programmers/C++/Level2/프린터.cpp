#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {

	int index = 0;
	for (int i = 1; i <= priorities.size(); i++)  // i : 출력 우선순위
	{
		int max_priority = *max_element(priorities.begin(), priorities.end());
		while (1)
		{
			if (priorities.at(index) == max_priority)
			{
				if (index == location) return i;
				priorities.at(index) = 0;
				break;
			}
			else index = (index + 1) % priorities.size();
		}
	}

	return -1;
}
