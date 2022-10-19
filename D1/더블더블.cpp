#include <iostream>
#include <cmath>

using namespace std;

int main() {

	int N;
	cin >> N;

	for (int i = 0; i <= N; i++)
		cout << pow(2, i) << ' ';

	return 0;
}