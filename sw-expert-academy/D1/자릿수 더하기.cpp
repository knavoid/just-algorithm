#include <iostream>

using namespace std;

int main() {

	int N, sum = 0;
	cin >> N;

	while (N) {
		sum += N % 10;
		N /= 10;
	}

	cout << sum;

	return 0;
}