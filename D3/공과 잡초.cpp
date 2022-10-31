#include <iostream>
#include <string>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int pos, answer = 0;
		string S;
		cin >> S;

		pos = -1;
		while ((pos = S.find("()", pos + 1)) != string::npos)
			answer++;

		pos = -1;
		while ((pos = S.find("(|", pos + 1)) != string::npos)
			answer++;

		pos = -1;
		while ((pos = S.find("|)", pos + 1)) != string::npos)
			answer++;

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}