#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;

int N, M, K;
int A[51][51];
int R[6], C[6], S[6];
int answer = INT_MAX;

void rotation(int r, int c, int s, int arr[51][51]) {
	int tmp = arr[r - s][c - s];
	// 왼쪽 
	for (int i = r - s + 1; i <= r + s; i++) {
		arr[i - 1][c - s] = arr[i][c - s];
	}

	// 아래쪽
	for (int j = c - s + 1; j <= c + s; j++) {
		arr[r + s][j - 1] = arr[r + s][j];
	}

	// 오른쪽
	for (int i = r + s - 1; i >= r - s; i--) {
		arr[i + 1][c + s] = arr[i][c + s];
	}

	// 위쪽
	for (int j = c + s - 1; j >= c - s + 1; j--) {
		arr[r - s][j + 1] = arr[r - s][j];
	}
	arr[r - s][c - s + 1] = tmp;
}

void permutation(int cnt, int selected, int arr[51][51]) {
	// K번의 연산이 모두 수행되면
	if (cnt == K) {
		for (int i = 1; i <= N; i++) {
			answer = min(answer, accumulate(arr[i] + 1, arr[i] + M + 1, 0));
		}
		return;
	}
	// 순서 정하기
	for (int i = 0; i < K; i++) {
		if ((selected & (1 << i)) == 0) {
			int copyarr[51][51];
			copy(&arr[0][0], &arr[0][0] + 2601, &copyarr[0][0]);
			
			// 연산 수행
			int r = R[i], c = C[i], s = S[i];
			while (s > 0) {
				rotation(r, c, s--, copyarr);
			}
			
			// 다음 순서로 이동
			permutation(cnt + 1, selected | (1 << i), copyarr);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// initialize
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> R[i] >> C[i] >> S[i];
	}

	// solution
	permutation(0, 0, A);

	// result
	cout << answer;

	return 0;
}