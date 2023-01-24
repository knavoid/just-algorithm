#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		string str;
		cin >> str;

		set<char> alphabet;
		for (char c : str) {
			if (alphabet.find(c) == alphabet.end()) // 알파벳이 set에 없는 경우
				alphabet.insert(c);
			else // 알파벳이 set에 이미 존재하여 짝이 이루어진 경우
				alphabet.erase(c);
		}

		string answer;
		for (char c : alphabet)
			answer += c;

		cout << '#' << t << ' ';
		answer.empty() ? cout << "Good" : cout << answer;
		cout << '\n';
	}

	return 0;
}