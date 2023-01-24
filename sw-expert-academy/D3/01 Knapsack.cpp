#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N, K, V, C;
		cin >> N >> K;

		// i : 부피, values[i] : 가치의 최대값
		vector<int> values(K + 1, -1);
		values[0] = 0;

		for (int i = 0; i < N; i++) {
			cin >> V >> C;
			for (int j = K; j >= V; j--)
				if (values[j - V] >= 0)
					values[j] = max(C + values[j - V], values[j]);
		}

		int answer = *max_element(values.begin(), values.end());
		cout << '#' << tc << ' ' << answer << '\n';
	}
	
	return 0;
}