#include <iostream>
#include <string>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		string str, answer;
		cin >> str;

		int front = stoi(str.substr(0, 2));
		int back = stoi(str.substr(2, 2));

		bool m1 = 1 <= front && front <= 12;
		bool m2 = 1 <= back && back <= 12;

		if (m1 && m2)
			answer = "AMBIGUOUS";
		else if (m1)
			answer = "MMYY";
		else if (m2)
			answer = "YYMM";
		else
			answer = "NA";

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}