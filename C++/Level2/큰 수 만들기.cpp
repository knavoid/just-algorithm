#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {

	string answer = "";

	int start = 0;  // 탐색 시작 위치
	int erase = k;  // 제거 가능한 수
	for (int i = 0; i < number.size() - k; i++)  // 반환 할 자릿 수만큼 반복
	{
		int max_index = start;
		for (int j = start; j <= start + erase; j++)
			if (number[j] > number[max_index])
				max_index = j;

		erase -= (max_index - start);
		start = max_index + 1;

		answer += number[max_index];
	}

	return answer;
}
