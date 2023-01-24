#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, number;
		cin >> N;

		vector<int> numberCount(N); // 각 숫자의 개수를 저장
		for (int i = 0; i < N; i++) {
			cin >> number;
			numberCount[number - 1]++;
		}

		cout << '#' << t << ' ';
		// 모든 개수가 1인 경우 Yes를, 그렇지 않은 경우 No를 출력
		count(numberCount.begin(), numberCount.end(), 1) == N ?
			cout << "Yes\n" : cout << "No\n";
	}

	return 0;
}