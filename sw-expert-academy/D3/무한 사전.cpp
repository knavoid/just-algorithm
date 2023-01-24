#include <iostream>
#include <string>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		char answer = 'Y';
		string word1, word2;
		cin >> word1 >> word2;

		if (word1.length() != 10 && word1 + 'a' == word2)
			answer = 'N';

		cout << '#' << tc << ' ' << answer << '\n';;
	}

	return 0;
}