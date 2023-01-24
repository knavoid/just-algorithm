#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	for (int tc = 1; tc <= 10; tc++) {
		int N, H; // N: 덤프 횟수, H: 박스 높이
		int maxH = 1, minH = 100;
		int box[101] = { };
		cin >> N;

		for (int i = 0; i < 100; i++) {
			cin >> H;
			maxH = max(H, maxH);
			minH = min(H, minH);
			box[H]++;
		}

		for (int i = 0; i < N; i++) {
			if (maxH - minH == 1)
				break;

			// 가장 높은 상자 하나 가져오기
			box[maxH]--; box[maxH - 1]++;
			if (box[maxH] == 0)
				maxH--;

			// 가장 낮은 곳에 상자 하나 두기
			box[minH]--; box[minH + 1]++;
			if (box[minH] == 0)
				minH++;
		}

		cout << '#' << tc << ' ' << maxH - minH << '\n';
	} 

	return 0;
}