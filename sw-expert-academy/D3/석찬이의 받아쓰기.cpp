#include <iostream>
#include <string>

using namespace std;

int main() {
	
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, answer = 0;
		string str1, str2;
		cin >> N >> str1 >> str2;

		for (int i = 0; i < N; i++)
			if (str1[i] == str2[i])
				answer++;

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}