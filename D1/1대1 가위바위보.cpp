#include <iostream>

using namespace std;

int main() {

	int A, B;
	cin >> A >> B;

	A == B % 3 + 1 ? cout << 'A' : cout << 'B';

	return 0;
}