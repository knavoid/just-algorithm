#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int N, vector<pair<int, int>> height) {
	int answer = 0;
	
	// 첫번째 전봇대에 걸린 전선 높이 기준 오름차순 정렬
	sort(height.begin(), height.end());

	// 첫번째 연결 높이는 더 낮으면서 두번재 연결 높이는 더 높은 전선의 수 세기
	for (int i = 1; i < N; i++) {
		int h1 = height[i].second;
		for (int j = 0; j < i; j++) {
			int h2 = height[j].second;
			if (h1 < h2)
				answer++;
		}
	}

	return answer;
}

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;

		vector<pair<int, int>> height(N);
		for (int i = 0; i < N; i++)
			cin >> height[i].first >> height[i].second;

		cout << '#' << t << ' ' << solution(N, height) << '\n';
	}

	return 0;
}