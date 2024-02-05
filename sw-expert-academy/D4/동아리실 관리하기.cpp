#include <iostream>
#include <string>

using namespace std;

int T, N;
string seq;
int cases[10000][16];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		// initialize
		cin >> seq;
		N = seq.length();
		fill(&cases[0][0], &cases[N - 1][16], 0);
		// A가 열쇠를 가지고 있다.
		for (int j = 1; j < 16; j++) {
			int mask = 1 | (1 << (seq[0] - 'A'));
			if (j == (j | mask)) {
				cases[0][j] = 1;
			}
		}
		// 전날의 경우의 수와 비교하는 동적계획법
		for (int i = 1; i < N; i++) {
			int mask = (1 << (seq[i] - 'A')); // C
			for (int j = 1; j < 16; j++) {
				if (j == (j | mask)) {
					for (int k = 1; k < 16; k++) {
						if ((0 < cases[i - 1][k]) && ((j & k) != 0)) {
							cases[i][j] = (cases[i][j] + cases[i - 1][k]) % 1000000007;
						}
					}
				}
			}
		}
		// 최종 경우의수 합산
		int answer = 0;
		for (int j = 1; j < 16; j++) {
			answer = (answer + cases[N - 1][j]) % 1000000007;
		}
		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}