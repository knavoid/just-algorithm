#include <iostream>
#include <deque>

using namespace std;

int main() {

	for (int tc = 1; tc <= 10; tc++) {
		int N, M; // N: 암호문 길이, M: 명령어 개수
		int V; // V: 입력 값
		deque<int> pw;

		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> V;
			pw.push_back(V);
		}

		cin >> M;
		for (int i = 0; i < M; i++) {
			char c;
			int x, y, s;
			cin >> c >> x >> y;
			
			if (c == 'I') {
				for (int j = 0; j < y; j++) {
					cin >> s;
					pw.insert(pw.begin() + x++, s);
				}
			}
			else // c == 'D'
				pw.erase(pw.begin() + x, pw.begin() + x + y);
		}

		cout << '#' << tc << ' ';
		for (int i = 0; i < 10; i++)
			cout << pw[i] << ' ';
		cout << '\n';
	}

	return 0;
}