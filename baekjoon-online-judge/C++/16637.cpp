#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N;
string str;
vector<int> numbers;
vector<char> operators;
vector<int> bracket;
int answer = INT_MIN;

int calc() {
	vector<int> numbers_ = numbers;
	vector<char> operators_ = operators;
	// 괄호 먼저 계산
	for (int i = 0; i < bracket.size(); i++) {
		int idx = bracket[i] - i;
		if (operators_[idx] == '+') {
			numbers_[idx] += numbers_[idx + 1];
		}
		else if (operators_[idx] == '-') {
			numbers_[idx] -= numbers_[idx + 1];
		}
		else if (operators_[idx] == '*') {
			numbers_[idx] *= numbers_[idx + 1];
		}
		numbers_.erase(numbers_.begin() + idx + 1);
		operators_.erase(operators_.begin() + idx);
	}

	// 나머지 순서대로 계산
	int result = numbers_.front();
	for (int i = 0; i < operators_.size(); i++) {
		if (operators_[i] == '+') {
			result += numbers_[i + 1];
		}
		else if (operators_[i] == '-') {
			result -= numbers_[i + 1];
		}
		else if (operators_[i] == '*') {
			result *= numbers_[i + 1];
		}
	}

	return result;
}

void selectBracket(int pos) {
	if (pos >= N / 2) {
		answer = max(answer, calc());
		return;
	}

	// 현재 위치에 괄호를 두는 경우
	bracket.push_back(pos);
	selectBracket(pos + 2);
	bracket.pop_back();

	// 현재 위치에 괄호를 두지 않는 경우
	selectBracket(pos + 1);
}

int main() {
	// initialize
	cin >> N >> str;

	// 연산자와 숫자 분리
	for (char c : str) {
		if (isdigit(c)) {
			numbers.push_back(c - '0');
		}
		else {
			operators.push_back(c);
		}
	}

	// 괄호 선택
	selectBracket(0);

	// result
	cout << answer;

	return 0;
}