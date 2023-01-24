#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;


	for (int t = 1; t <= T; t++) {
		int N, card, totalValue = 0;
		cin >> N;

		// 가치별 남은 카드수
		int values[12] = { 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 16, 4 };

		for (int i = 0; i < N; i++) {
			cin >> card;
			totalValue += card;
			values[card]--;
		}

		// STOP을 위한 카드수와 GAZUA를 위한 카드수
		int remainValue = 21 - totalValue;
		int stopCount = 52 - N, gazuaCount = 0;
		for (int v = 2; v <= remainValue; v++) {
			stopCount -= values[v];
			gazuaCount += values[v];
		}

		cout << '#' << t << ' ';
		stopCount >= gazuaCount ? cout << "STOP\n" : cout << "GAZUA\n";
	}

	return 0;
}