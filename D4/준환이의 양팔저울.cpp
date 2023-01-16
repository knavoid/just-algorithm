#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int T, N, answer;
int weight[10]; // 추의 무게들
int weightSum; // 추의 전체 무게 합
bool selected[10]; // 추의 선택 여부

int exponential2[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
int factorial[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

// 순서별 추 올리는 위치 선택 (올린 추의 수, 왼쪽 무게 합, 오른쪽 무게 합, 남은 무게)
void select(int cnt, int left, int right) {

	// 모든 추를 올린 경우
	if (cnt == N) {
		answer++;
		return;
	}

	// 남은 추를 모두 오른쪽에 올려도 문제 없는 경우
	if (left * 2 >= weightSum) {
		answer += exponential2[N - cnt] * factorial[N - cnt];
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!selected[i]) {
			selected[i] = true;

			// 왼쪽에 추를 올리는 경우
			select(cnt + 1, left + weight[i], right);

			// 오른쪽에 추를 올리는 경우
			if (left >= right + weight[i])
				select(cnt + 1, left, right + weight[i]);

			selected[i] = false;
		}
	}
}

int main() {

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		// init
		answer = 0;
		weightSum = 0;

		// input
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> weight[i];
			weightSum += weight[i];
			selected[i] = false;
		}

		// solution
		select(0, 0, 0);

		// output
		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}