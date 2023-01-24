#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {

	cin.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int numbers[7];
		for (int i = 0; i < 7; i++)
			cin >> numbers[i];

		// 중복되지 않도록 모든 합을 계산
		set<int> sum;
		for (int i = 0; i < 7; i++)
			for (int j = i + 1; j < 7; j++)
				for (int k = j + 1; k < 7; k++)
					sum.insert(numbers[i] + numbers[j] + numbers[k]);

		// 합들중에서 5번째로 큰 수를 출력
		vector<int> result(sum.rbegin(), sum.rend());
		cout << '#' << t << ' ' << result[4] << '\n';
	}

	return 0;
}