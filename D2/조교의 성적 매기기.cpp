#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T, N, K;
	int s1, s2, s3, total;
	string grade[10] = {"A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0"};

	cin >> T;

	for (int t = 1; t <= T; t++) {
		vector<pair<int, int>> scoreSeq;

		cin >> N >> K;

		for (int i = 1; i <= N; i++) {
			cin >> s1 >> s2 >> s3;
			total = (s1 * 35) + (s2 * 45) + (s3 * 20);
			scoreSeq.push_back(make_pair(total, i));
		}

		sort(scoreSeq.begin(), scoreSeq.end(), greater<pair<int, int>>());

		for (int rank = 0; rank < N; rank++) {
			if (scoreSeq[rank].second == K) {
				cout << '#' << t << ' ' << grade[rank / (N / 10)] << '\n';
				break;
			}
		}
	}

	return 0;
}