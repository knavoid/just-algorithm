#include <iostream>
#include <string>

using namespace std;

string solution(int N) {
	for (int a = 1; a <= 9; a++)
		for (int b = 1; b <= 9; b++)
			if (a * b == N)
				return "Yes";
	return "No";
}

int main() {

	int T, N;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;
		cout << '#' << t << ' ' << solution(N) << '\n';
	}

	return 0;
}