#include <iostream>
#include <string>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		string word, answer;

		for (int i = 0; i < 3; i++) {
			cin >> word;
			answer += toupper(word.front());
		}

		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}