#include <string>
#include <vector>

using namespace std;

string jinsu(int num, int n) {
	
	string result = "";

	while (num)
	{
		int remain = num % n;
		if (remain < 10) result = to_string(remain) + result;
		else result = (char)(remain + 55) + result;
		num /= n;
	}

	return result;
}

string solution(int n, int t, int m, int p) {

	string sequence = "0";
	string answer = "";

	for (int i = 1; sequence.length() < t * m; i++)
		sequence.append(jinsu(i, n));

	for (int i = p - 1; i < sequence.length(); i += m)
		answer.append(sequence.substr(i, 1));

	return answer.substr(0, t);
}
