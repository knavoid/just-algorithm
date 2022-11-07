#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int K, n;
		cin >> K;

		int N = pow(2, K) - 1;
		vector<int> vertex(N);
		for (int i = 0; i < N; i++)
			cin >> vertex[i];

		queue<pair<int, int>> tree;
		tree.push(make_pair(0, N));

		vector<int> answer; // 결과 저장
		while (!tree.empty()) {
			pair<int, int> p = tree.front();
			tree.pop();

			// 중앙의 수를 저장
			int len = p.second - p.first;
			int mid = (p.first + p.second) / 2;
			answer.push_back(vertex[mid]);

			// 좌측과 우측의 문자열로 반복
			if (len > 1) {
				tree.push(make_pair(mid - len / 2, mid));
				tree.push(make_pair(mid + 1, mid + len / 2 + 1));
			}
		}

		// 결과 출력
		cout << '#' << tc << ' ';
		int e = 1;
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << ' ';
			if (i == pow(2, e) - 2) {
				e++;
				cout << '\n';
			}
		}
	}

	return 0;
}