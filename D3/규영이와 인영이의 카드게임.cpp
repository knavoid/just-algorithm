#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int win = 0, lose = 0;
		bool selected[18] = {}; // 카드 선택 여부
		int cards1[9]; // 규영이 카드
		int cards2[9]; // 인영이 카드

		// 규영이 카드
		for (int i = 0; i < 9; i++) {
			cin >> cards1[i];
			selected[cards1[i] - 1] = true;
		}

		// 인영이 카드 종류 (오름차순)
		int idx = 0;
		for (int i = 0; i < 18; i++)
			if (!selected[i])
				cards2[idx++] = i + 1;

		do {
			int score1 = 0; // 규영이 점수 
			int score2 = 0; // 인영이 점수
			for (int i = 0; i < 9; i++)
				if (cards1[i] != cards2[i])
					cards1[i] > cards2[i] ?
					score1 += cards1[i] + cards2[i] :
					score2 += cards1[i] + cards2[i];
			if (score1 != score2)
				score1 > score2 ? win++ : lose++;
		} while (next_permutation(cards2, cards2 + 9));

		cout << '#' << t << ' ' << win << ' ' << lose << '\n';
	}

	return 0;
}