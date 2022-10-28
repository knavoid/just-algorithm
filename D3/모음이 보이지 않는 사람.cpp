#include <iostream>
#include <string>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		string str;
		cin >> str;

		cout << '#' << t << ' ';
		for (char c : str)
			if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
				cout << c;
		cout << '\n';
	}


	return 0;
}