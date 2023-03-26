#include <iostream>
#include <set>

using namespace std;

int N, number;
set<int> numbers;

int main() {
	// initialize
	cin >> N;
	while (N--) {
		cin >> number;
		numbers.insert(number);
	}

	// result
	for (int number : numbers) {
		cout << number << ' ';
	}

	return 0;
}