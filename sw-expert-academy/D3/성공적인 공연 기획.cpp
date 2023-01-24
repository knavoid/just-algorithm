#include <iostream>
#include <string>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int answer = 0, clapping = 0;
		string str;
		cin >> str;

		int len = str.length();
		for (int i = 0; i < len; i++) {
			int n = str[i] - '0';
			if (i > clapping) {
				answer += i - clapping;
				clapping += i - clapping;
			}
			clapping += n;
		}

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}