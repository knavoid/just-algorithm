#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	int T;
	unordered_map<char, int> cardMap = { {'S', 0}, {'D', 1}, {'H', 2}, {'C', 3} };
	cin >> T;

	for (int t = 1; t <= T; t++) {
		string str;
		bool error = false;
		int cards[4][13] = { 0 };
		cin >> str;
		
		int len = str.length();
		for (int i = 0; i < len; i += 3) {
			char type = str[i];
			int number = stoi(str.substr(i + 1, 2));
			if (cards[cardMap[type]][number - 1] != 0) {
				error = true;
				break;
			}
			cards[cardMap[type]][number - 1]++;
		}

		cout << '#' << t << ' ';
		if (error)
			cout << "ERROR\n";
		else {
			for (int i = 0; i < 4; i++) 
				cout << count(cards[i], cards[i] + 13, 0) << ' ';
			cout << '\n';
		}
	}

	return 0;
}