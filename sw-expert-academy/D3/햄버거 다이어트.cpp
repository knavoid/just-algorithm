#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int answer = 0;
		int N, L, flavor, calorie;
		cin >> N >> L;

		vector<int> hamburger(L + 1, -1); // 칼로리당 맛점수를 표시
		hamburger[0] = 0;

		for (int i = 0; i < N; i++) {
			cin >> flavor >> calorie;
			for (int j = L; j >= calorie; j--)
				if (hamburger[j - calorie] >= 0)
					hamburger[j] = max(hamburger[j], flavor + hamburger[j - calorie]);
		}

		// 가장 맛 점수가 높은 햄버거 구하기
		answer = *max_element(hamburger.begin(), hamburger.end());
		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}