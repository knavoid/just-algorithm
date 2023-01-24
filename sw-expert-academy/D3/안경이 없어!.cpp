#include <iostream>
#include <string>

using namespace std;

int getHole(char c) {

	string hole[3] = { "CEFGHIJKLMNSTUVWXYZ", "ADOPQR", "B" };

	for (int h = 0; h < 3; h++)
		if (hole[h].find(c) != string::npos)
			return h;

	return -1;
}

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		string str1, str2, answer = "SAME";
		cin >> str1 >> str2;

		int len1 = str1.length();
		int len2 = str2.length();

		if (len1 != len2)
			answer = "DIFF";
		else {
			for (int i = 0; i < len1; i++) {
				if (getHole(str1[i]) != getHole(str2[i])) {
					answer = "DIFF";
					break;
				}
			}
		}

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}