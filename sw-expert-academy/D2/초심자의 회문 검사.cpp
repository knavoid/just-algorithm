#include <iostream>
#include <string>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int answer = 1;
		string sentence;
		cin >> sentence;

		int len = sentence.length();
		for (int i = 0; i < len / 2; i++) {
			if (sentence[i] != sentence[len - i - 1]) {
				answer = 0;
				break;
			}
		}

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}