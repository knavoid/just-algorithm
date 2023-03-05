#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int P[10][10]; // 입력한 종이
int paperCount[6] = { 0, 5, 5, 5, 5, 5 }; // 크기별 남은 색종이의 개수
bool canCover; // 주어진 색종이들로 덮을 수 있는지 
int answer = INT_MAX; // 필요한 색종이의 최소 개수

bool isCovered(int paper[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (paper[i][j] == 1) {
				return false;
			}
		}
	}
	return true;
}

int getMaxSize(int x, int y, int paper[10][10]) {
	for (int size = 2; size <= 5; size++) {
		for (int i = x; i < x + size; i++) {
			for (int j = y; j < y + size; j++) {
				if (i < 0 || i >= 10 || j < 0 || j >= 10) {
					return size - 1;
				}
				if (paper[i][j] == 0) {
					return size - 1;
				}
			}
		}
	}
	return 5;
}

void cover(int cnt, int paper[10][10]) {
	if (cnt >= answer) {
		return;
	}

	if (isCovered(paper)) {
		canCover = true;
		answer = min(answer, cnt);
		return;
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (paper[i][j] == 1) {
				int maxSize = getMaxSize(i, j, paper);
				for (int size = maxSize; size >= 1; size--) {
					if (paperCount[size] > 0) {
						paperCount[size]--;
						// 종이 복사 후 size만큼 지우기
						int cpaper[10][10];
						copy(&paper[0][0], &paper[0][0] + 100, &cpaper[0][0]);
						for (int x = i; x < i + size; x++) {
							for (int y = j; y < j + size; y++) {
								cpaper[x][y] = 0;
							}
						}
						// 다음으로 덮을곳은?
						cover(cnt + 1, cpaper);
						paperCount[size]++;
					}
				}
				return;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// initialize
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> P[i][j];
		}
	}

	// solution
	cover(0, P);

	// result
	canCover ? cout << answer : cout << -1;

	return 0;
}