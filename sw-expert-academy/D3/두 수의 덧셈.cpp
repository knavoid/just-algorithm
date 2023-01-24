#include <iostream>
#include <string>

using namespace std;

string sum(string A, string B) {
	
	string result;
	int carry = 0;

	while (!A.empty() && !B.empty()) {
		int sum = (A.back() - '0') + (B.back() - '0') + carry;
		A.pop_back();
		B.pop_back();

		if (sum >= 10) {
			sum -= 10;
			carry = 1;
		}
		else
			carry = 0;

		result = to_string(sum) + result;
	}

	if (A.empty() && B.empty())
		result = (carry ? "1" : "") + result;
	else if (A.empty())
		result = (carry ? sum(B, "1") : B) + result;
	else if (B.empty())
		result = (carry ? sum(A, "1") : A) + result;

	return result;
}

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		string A, B;
		cin >> A >> B;

		cout << '#' << t << ' ' << sum(A, B) << '\n';
	}

	return 0;
}