#include <iostream>

using namespace std;

int main() {

	int N;
	cin >> N;

	for (int n = 1; n <= N; n++)
		if (N % n == 0)
			cout << n << ' ';

	return 0;
}