#include <iostream>
#include <string>

using namespace std;

// 문자열 내에서 반복되는 가장 짧은 문자열 반환
string substring(string str) {
	int len = str.length();
	int minLen = len;

	for (int l = len / 2; l >= 1; l--) {
		if (len % l == 0) {
			bool isRepeat = true;
			string sub = str.substr(0, l);
			for (int i = l; i < len; i += l) {
				if (str.substr(i, l) != sub) {
					isRepeat = false;
					break;
				}
			}
			if (isRepeat)
				minLen = l;
		}
	}

	return str.substr(0, minLen);
}

int main() {

	int T;
	string answer;
	string str1, str2;
	
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		// initialize
		cin >> str1 >> str2;

		// solution
		answer = substring(str1) == substring(str2) ? "yes" : "no";

		// result
		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}