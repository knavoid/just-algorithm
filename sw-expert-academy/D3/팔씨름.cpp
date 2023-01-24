#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		string str;
		cin >> str;

		int remain = 15 - str.length();
		int win = count(str.begin(), str.end(), 'o');
		string answer = win + remain >= 8 ? "YES" : "NO";

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}