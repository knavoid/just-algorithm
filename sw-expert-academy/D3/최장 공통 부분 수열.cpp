#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		string str1, str2;
		cin >> str1 >> str2;

		int len1 = str1.length();
		int len2 = str2.length();
		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));

		for (int i = 1; i <= len1; i++) 
			for (int j = 1; j <= len2; j++) 
				dp[i][j] = str1[i - 1] == str2[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);

		cout << '#' << t << ' ' << dp[len1][len2] << '\n';
	}

	return 0;
}