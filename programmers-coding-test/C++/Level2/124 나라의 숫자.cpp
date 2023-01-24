#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(int n) {

	int len = 1;  // 124나라의 수로 변경하였을 때의 숫자 길이
	int value = 3;
	string n124 = "";
	string num[3] = { "1", "2", "4" };

	while (n > value)
	{
		n -= value;
		value *= 3;
		len++;
	}

	// len길이에서의 n번째 수를 찾는다.

	n--;

	for (int i = len - 1; i >= 0; i--)
	{
		int range = pow(3, i);
		n124.append(num[n / range]);
		n = n % range;
	}

	return n124;
}
