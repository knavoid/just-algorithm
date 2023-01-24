#include <iostream>
#include <string>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		string str, str1, str2, str3, answer;
		cin >> str;

		int len = str.length();
		
		// str1
		for (int i = 0; i < len; i++)
			str1 += "..#.";
		str1 += ".\n";

		// str2
		for (int i = 0; i < len; i++)
			str2 += ".#.#";
		str2 += ".\n";

		// str3
		for (int i = 0; i < len; i++)
			str3 += "#." + str.substr(i, 1) + ".";
		str3 += "#\n";

		cout << str1 + str2 + str3 + str2 + str1;
	}

	return 0;
}