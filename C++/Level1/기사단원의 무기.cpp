#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
	int answer = 0;
	vector<int> powers(number, 1);

	for (int i = 2; i <= number; i++) 
		for (int j = i; j <= number; j += i) 
			powers[j - 1]++;

	for (int p : powers) 
		answer += (p <= limit) ? p : power;

	return answer;
}