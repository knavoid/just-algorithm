#include <iostream>
#include <vector>
#include <set>
#include <queue>

#define N 100

using namespace std;

pair<int, int> answer; // 연락 받는 시간, 연락 받는 사람
int M, B; // N: 입력 데이터 길이, B: 연락 시작점
int from, to, person, contactTime;
vector<set<int>> contact;
vector<bool> visited;
queue<pair<int, int>> q;

int main() {

	for (int tc = 1; tc <= 10; tc++) {
		// initialize
		answer = make_pair(0, 0);
		contact.assign(N + 1, {});
		visited.assign(N + 1, false);
		cin >> M >> B;
		visited[B] = true;
		q.push(make_pair(B, 0));

		for (int i = 0; i < M / 2; i++) {
			cin >> from >> to;
			contact[from].insert(to);
		}

		// solution
		while (!q.empty()) {
			person = q.front().first;
			contactTime = q.front().second;
			answer = max(answer, make_pair(contactTime, person));
			q.pop();

			for (int p : contact[person]) {
				if (!visited[p]) {
					visited[p] = true;
					q.push(make_pair(p, contactTime + 1));
				}
			}
		}

		// result
		cout << '#' << tc << ' ' << answer.second << '\n';
	}

	return 0;
}