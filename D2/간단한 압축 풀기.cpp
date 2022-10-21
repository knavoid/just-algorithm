#include <iostream>
#include <string>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		char Ci; int Ki;
		string answer;

		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> Ci >> Ki;
			for (int k = 0; k < Ki; k++) {
				if (answer.length() % 11 == 0)
					answer += '\n'; 
				answer += Ci;
			}
		}

		cout << '#' << t << answer << '\n';
	}

	return 0;
}