#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N; // 세로선의 개수
int M; // 가로선의 개수
int H; // 가로선을 놓을 수 있는 위치의 개수
bool ladder[31][11];
vector<pair<int, int>> possible;
int answer = 4;

bool checkLadder() {
	// 각 세로선에서 사다리 타기
	for (int line = 1; line <= N; line++) {
		int j = line;
		for (int i = 1; i <= H; i++) {
			if (ladder[i][j - 1]) { 
				j--; // 왼쪽 이동
			} else if (ladder[i][j]) { 
				j++; // 오른쪽 이동
			}
		}
		// 사다리 결과 번호가 같지 않은 경우
		if (j != line) { 
			return false;
		}
	}
	return true;
}

// 사다리 추가 (cnt: 추가한 사다리 수, line: 탐색 시작 세로선)
void addLadder(int cnt, int line) {
	// 가로줄을 최소값보다 더 추가한 경우
	if (cnt >= answer) {
		return;
	}
	// 사다리 결과가 모두 같은 번호인지 확인
	if (checkLadder()) {
		answer = min(answer, cnt);
	}
	// 가로줄을 3회이상 추가한 경우
	if (cnt >= 3) {
		return;
	}
	// 가로줄 추가
	for (int j = line; j < N; j++) {
		for (int i = 1; i <= H; i++) {
			// 사다리 추가 가능한 경우
			if (!ladder[i][j - 1] && !ladder[i][j] && !ladder[i][j + 1]) {
				ladder[i][j] = true;
				addLadder(cnt + 1, j);
				ladder[i][j] = false;
			}
		}
	}
}

int main() {
	// initialize
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		ladder[a][b] = true;
	}

	// solution
	addLadder(0, 1);

	// result
	answer <= 3 ? cout << answer : cout << -1;

	return 0;
}