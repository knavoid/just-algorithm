#include <iostream>

using namespace std;

int main() {

	int N, sum = 0;
	cin >> N;

	for (int n = 1; n <= N; n++)
		sum += n;

	cout << sum;

	return 0;
}