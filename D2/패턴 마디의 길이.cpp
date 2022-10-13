#include <iostream>
#include <string>

using namespace std;

bool isRepeat(string str, int len) {
	string word = str.substr(0, len);
	for (int i = len; i < str.length(); i += len) {
		string subStr = str.substr(i, len);
		if (word.length() == subStr.length() && word != subStr)
			return false;  // 부분 문자열이 마디와 동일하지 않은 경우
		else if (word.find(subStr) != 0)
			return false;  // 부분 문자열이 마디의 시작부분과 같지 않은 경우
	}
	return true;
}

int main()
{
	int T;
	string str;

	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> str;

		for (int len = 1; len <= 10; len++) {
			if (isRepeat(str, len)) {
				cout << '#' << t << ' ' << len << '\n';
				break;
			}
		}
	}

	return 0;
}