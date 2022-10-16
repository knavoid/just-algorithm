#include <iostream>
#include <string>

using namespace std;

// 받은 패턴이 팰린드롬과 매치되는지 판단하는 함수
string existPalindrome(string pattern) {

	int len = pattern.length();

	for (int i = 0; i < len / 2; i++) {
		char c1 = pattern[i];
		char c2 = pattern[len - i - 1];
		if (c1 == '*' || c2 == '*')
			break;
		if (c1 != c2)
			return "Not exist";
	}
	return "Exist";
}

int main() {
	 
	int T;
	cin >> T;
	
	for (int t = 1; t <= T; t++) {
		string pattern;
		cin >> pattern;

		cout << '#' << t << ' ' << existPalindrome(pattern) << '\n';
	}

	return 0;
}