#include <iostream>
#include <string>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int answer = 0;
		string str;
		cin >> str;

		for (int i = 0; i < 26; i++) {
			if (str[i] != i + 'a')
				break;
			answer++;
		}

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}