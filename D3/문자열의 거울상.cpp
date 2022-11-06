#include <iostream>
#include <string>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		string str, answer;
		cin >> str;

		int len = str.length();
		for (int i = len - 1; i >= 0; i--) {
			char c = str[i];
			if (c == 'b')
				answer += 'd';
			else if (c == 'd')
				answer += 'b';
			else if (c == 'p')
				answer += 'q';
			else
				answer += 'p';
		}

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}