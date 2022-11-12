#include <iostream>
#include <string>

using namespace std;

int main() {

	for (int tc = 1; tc <= 10; tc++) {
		int answer = 0, pos = -1;
		string s, str;
		cin >> tc >> s >> str;

		while ((pos = str.find(s, pos + 1)) != string::npos)
			answer++;

		cout << '#' << tc << ' ' << answer << '\n';
	} 

	return 0;
}