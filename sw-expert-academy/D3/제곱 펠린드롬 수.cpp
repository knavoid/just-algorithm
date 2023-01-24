#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPalindrome(int n) {

	string str1 = to_string(n); // 원본 문자열
	string str2 = str1;				// 뒤집을 문자열
	reverse(str2.begin(), str2.end());

	return str1 == str2;
}

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int A, B, answer = 0;
		cin >> A >> B;

		for (int n = ceil(sqrt(A)); n * n <= B; n++)
			if (isPalindrome(n) && isPalindrome(n * n)) 
				answer++;

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}