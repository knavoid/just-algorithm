#include <string>
#include <stack>

using namespace std;

int solution(string s) {

	stack<char> jjak;
	for (char c : s)
	{
		if (!jjak.empty() && c == jjak.top()) jjak.pop();
		else jjak.push(c);
	}

	return jjak.empty();
}
