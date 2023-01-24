#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int T, K;
string str;
vector<string> suffix;

int main() {

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		// initialize
		cin >> K >> str;
		suffix.clear();

		// solution
		for (int i = 0; i < str.length(); i++) 
			suffix.push_back(str.substr(i));
		
		sort(suffix.begin(), suffix.end());

		// result
		cout << '#' << tc << ' ' << suffix[K - 1] << '\n';
	}

	return 0;
}