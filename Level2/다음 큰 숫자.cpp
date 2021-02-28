#include <string>
#include <vector>

using namespace std;

int binaryOneCount(int n) {  // 이진수에서의 1의 개수 반환

	string binary = "";
	int count = 0;

	while (n)
	{
		binary = to_string(n % 2) + binary;
		n /= 2;
	}

	for (char c : binary)
		if (c == '1') count++;

	return count;
}

int solution(int n) {

	int answer = n + 1;
	int one_count = binaryOneCount(n);

	while (binaryOneCount(answer) != one_count) answer++;

	return answer;
}
