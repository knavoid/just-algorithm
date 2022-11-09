#include <iostream>

using namespace std;

// & 함수
pair<int, int> ampersand(int n) {

	int len = 1;
	while (len < n) 
		n -= len++;
	
	return make_pair(n, len - n + 1);
}

// # 함수
int sharp(int x, int y) {

	int n = 0;
	for (int i = 0; i < x + y - 1; i++)
		n += i;

	return n + x;
}

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int p, q;
		cin >> p >> q;

		pair<int, int> ap = ampersand(p);
		pair<int, int> aq = ampersand(q);
		int answer = sharp(ap.first + aq.first, ap.second + aq.second);

		cout << '#' << tc << ' ' << answer << '\n';
	}
	
	return 0;
}