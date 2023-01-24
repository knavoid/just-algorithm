#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isMatch(string s1, string s2) {

	for (int i = 0; i < 8; i++) 
		if (s1[i] != '*' && s1[i] != s2[i])
			return false;
	
	return true;
}

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N, M, answer = 0;
		cin >> N >> M;

		vector<pair<string, int>> winning(N);
		for (int i = 0; i < N; i++)
			cin >> winning[i].first >> winning[i].second;

		string number;
		for (int i = 0; i < M; i++) {
			cin >> number;
			for (pair<string, int> w : winning)
				if (isMatch(w.first, number))
					answer += w.second;
		}

		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}