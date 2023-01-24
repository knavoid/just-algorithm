#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isCorrectSet(vector<int> cards) {

	int len = cards.size();
	if (len % 3 != 0)
		return false;

	vector<int> sequence;
	for (int i = 0; i < len / 3; i++) {
		sequence.push_back(i); sequence.push_back(i); sequence.push_back(i);
	}

	do {
		bool correct = true;
		vector<vector<int>> cardComb(len / 3); // 카드를 3장씩 나눈 조합
		for (int i = 0; i < len; i++)
			cardComb[sequence[i]].push_back(cards[i]);

		for (vector<int> v : cardComb) {
			sort(v.begin(), v.end());
			// 카드 3장이 각각 세트를 이루는지 확인
			if ((v[0] != v[1] || v[1] != v[2]) && 
				(v[0] + 1 != v[1] || v[1] + 1 != v[2]))
				correct = false;
		}

		if (correct)
			return true;

	} while (next_permutation(sequence.begin(), sequence.end()));

	return false;
}

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		string number, color;
		cin >> number >> color;

		// 색상별로 카드를 나누기
		vector<int> R, G, B;
		for (int i = 0; i < 9; i++) {
			char c = color[i];
			if (c == 'R')
				R.push_back(number[i] - '0');
			else if (c == 'G')
				G.push_back(number[i] - '0');
			else // c == 'B'
				B.push_back(number[i] - '0');
		}

		cout << '#' << tc << ' ';
		// 3개의 색상 모두 조건에 맞는 세트를 이룰 경우 "Win" 아닐 경우 "Continue"
		isCorrectSet(R) && isCorrectSet(G) && isCorrectSet(B) ? 
			cout << "Win\n" : cout << "Continue\n";
	}

	return 0;
}