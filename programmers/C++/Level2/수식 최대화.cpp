#include <string>
#include <vector>
#include <map>

using namespace std;

vector<char> oper;  // 사용하는 연산자 저장
vector<string> priority;  // 연산자 우선순위 조합
vector<int> used(3);

void find_priority(string pri) {

	if (pri.length() == oper.size()) {
		priority.push_back(pri);
		return;
	}

	for (int i = 0; i < oper.size(); i++) {
		if (used[i] == 0) {
			used[i] = 1;
			find_priority(pri + oper[i]);
			used[i] = 0;
		}
	}
}

long long solution(string expression) {
	
	long long max_value = 0;
	map<char, int> find_oper;
	vector<string> number_oper;

	for (char c : expression) {
		if (!isalnum(c)) find_oper[c] = 1;
	}

	for (auto iter : find_oper) {
		oper.push_back(iter.first);
	}

	find_priority("");

	int r1 = 0;
	while (1) {
		int r2 = r1;
		while (r2 < expression.length() && isalnum(expression[r2])) r2++;
		number_oper.push_back(expression.substr(r1, r2 - r1));
		if (r2 == expression.length()) break;
		number_oper.push_back(expression.substr(r2, 1));
		r1 = r2 + 1;
	}

	for (string s : priority) {
		vector<string> tmp = number_oper;
		for (char c : s) {
			int index = 0;
			while (index < tmp.size()) {
				if (tmp[index][0] == c) {

					long long value = stoll(tmp[index - 1]);
					if (c == '+') value += stoll(tmp[index + 1]);
					if (c == '-') value -= stoll(tmp[index + 1]);
					if (c == '*') value *= stoll(tmp[index + 1]);

					tmp.erase(tmp.begin() + index - 1, tmp.begin() + index + 2);
					if (index < tmp.size()) tmp.insert(tmp.begin() + index - 1, to_string(value));
					else tmp.push_back(to_string(value));
				}
				else index++;
			}
		}
		max_value = max(max_value, abs(stoll(tmp[0])));
	}

	return max_value;
}
