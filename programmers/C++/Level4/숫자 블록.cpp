#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(long long begin, long long end) {
	vector<int> answer;

	for (int i = begin; i <= end; i++) {
		bool pushed = false;
		for (int j = 2; j <= sqrt(i); j++) {
			// 가장 작은 약수로 나눈 수 = 가장 큰 약수
			if (i % j == 0 && i / j <= 10000000) {
				answer.push_back(i / j);
				pushed = true;
				break;
			}
		}
		if (!pushed) {
			if (i == 1) answer.push_back(0);
			else answer.push_back(1);
		}
	}

	return answer;
}
