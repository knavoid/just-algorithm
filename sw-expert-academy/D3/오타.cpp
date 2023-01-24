#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		long long answer = 1;
		string str;
		cin >> str;

		int len = str.length();
		for (int i = 0; i < len; i++) {
			unordered_set<char> hset;
			for (int j = max(0, i - 1); j <= min(len - 1, i + 1); j++) 
				hset.insert(str[j]);
			answer *= hset.size();
			answer %= 1000000007;
		}

		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}