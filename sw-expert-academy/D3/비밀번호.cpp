#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	for (int tc = 1; tc <= 10; tc++) {
		int N;
		string pw;
		cin >> N >> pw;

		vector<char> v;
		for (char c : pw) {
			if (v.empty())
				v.push_back(c);
			else if (v.back() == c)
				v.pop_back();
			else 
				v.push_back(c);
		}

		cout << '#' << tc << ' ';
		for (char c : v)
			cout << c;
		cout << '\n';
	}

	return 0;
}