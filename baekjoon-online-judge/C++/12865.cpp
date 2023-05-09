#include <iostream>
#include <algorithm>

using namespace std;

int N; // 물품의 수
int K; // 배낭 최대 무게
int knapsack[100001]; // 무게별 가치합의 최댓값

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// solution
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int w, v; // 물건의 무게와 가치
		cin >> w >> v;
		for (int j = K; j >= w; j--) {
			knapsack[j] = max(knapsack[j], v + knapsack[j - w]);
		}
	}

	// result
	cout << knapsack[K];

	return 0;
}