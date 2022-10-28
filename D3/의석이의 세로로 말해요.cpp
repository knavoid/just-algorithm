#include <iostream>
#include <string>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		string answer, words[5];
		for (int i = 0; i < 5; i++) 
			cin >> words[i];
		
		int idx = 0;
		while (1) {
			string str;
			for (int i = 0; i < 5; i++) 
				if (idx < words[i].length())
					str += words[i][idx];
			if (str.empty())
				break;
			answer += str;
			idx++;
		}

		cout << '#' << t << ' ' << answer << '\n';
	}


	return 0;
}