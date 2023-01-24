#include <iostream>
#include <string>

using namespace std;

int main() {

	string str;
	cin >> str;

	for (char c : str)
		cout << c - 'A' + 1 << ' ';

	return 0;
}