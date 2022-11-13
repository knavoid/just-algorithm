#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> numMap{ 
	{"ZRO", 0}, {"ONE", 1}, {"TWO", 2}, {"THR", 3}, {"FOR", 4}, 
	{"FIV", 5}, {"SIX", 6}, {"SVN", 7}, {"EGT", 8}, {"NIN", 9} };

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N;
		string testCase;
		cin >> testCase >> N;

		vector<string> numbers(N);
		for (int i = 0; i < N; i++)
			cin >> numbers[i];

		sort(numbers.begin(), numbers.end(), [](string x, string y) { return numMap[x] < numMap[y]; });

		cout << '#' << tc << '\n';
		for (string s : numbers)
			cout << s << ' ';
		cout << '\n';
	}

	return 0;
}