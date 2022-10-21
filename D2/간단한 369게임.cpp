#include <iostream>
#include <string>

using namespace std;

int main() {

	int N;
	cin >> N;

	for (int n = 1; n <= N; n++) {
		int clapCount = 0;
		string number = to_string(n);
		
		for (char c : number)
			if (c == '3' || c == '6' || c == '9')
				clapCount++;

		if (clapCount == 0)
			cout << number;
		else
			for (int i = 0; i < clapCount; i++)
				cout << '-';
		cout << ' ';
	}

	return 0;
}