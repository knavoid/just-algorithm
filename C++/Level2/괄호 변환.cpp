#include <string>
#include <vector>

using namespace std;

bool isBalanced(string p) {

	int left = 0, right = 0;
	for (char c : p)
	{
		if (c == '(') left++;
		if (c == ')') right++;
	}

	return left == right;
}

bool isCorrect(string p) {

	int stack = 0;
	for (char c : p)
	{
		if (c == '(') stack++;
		if (c == ')') stack--;
		
		if (stack < 0) return false;
	}

	return !stack;
}

string solution(string p) {

	if (p == "") return p;

	string u = "";
	string v = "";

	// u가 균형잡힌 문자열이 되도록 작업
	for (int i = 0; i < p.length(); i++)
	{
		u.append(p.substr(i, 1));
		if (isBalanced(u))
		{
			v = p.substr(i + 1);
			break;
		}
	}

	if (isCorrect(u)) 
		return u + solution(v);

	string uu = "";
	for (int i = 1; i < u.length() - 1; i++)
	{
		if (u.at(i) == '(') uu.append(")");
		if (u.at(i) == ')') uu.append("(");
	}

	return "(" + solution(v) + ")" + uu;
}
