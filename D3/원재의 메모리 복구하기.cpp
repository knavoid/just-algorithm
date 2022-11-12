#include <iostream>
#include <string>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int answer = 0;
		string memory;
		cin >> memory;
		memory = '0' + memory;

		int len = memory.length();
		for (int i = 0; i < len - 1; i++)
			if (memory[i] != memory[i + 1])
				answer++;

		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}