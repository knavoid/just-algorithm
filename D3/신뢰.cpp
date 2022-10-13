#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int T, N;

	cin >> T;

	for (int t = 1; t <= T; t++) {
		
		int time = 0;
		int Opos = 1, Bpos = 1;
		char robot; int button;
		queue<pair<int, int>> O, B;  // pair(pos, sequence)

		cin >> N;

		for (int i = 1; i <= N; i++) {
			cin >> robot >> button;
			if (robot == 'O')
				O.push(make_pair(button, i));
			else  // robot == 'B'
				B.push(make_pair(button, i));
		}

		while (!O.empty() || !B.empty()) {
			if (O.empty()) {
				int Bp = B.front().first;

				if (Bpos == Bp) 
					B.pop();
				else if (Bpos < Bp)
					Bpos++;
				else  // Bpos > Bp
					Bpos--;
			}
			else if (B.empty()) {
				int Op = O.front().first;

				if (Opos == Op) 
					O.pop();
				else if (Opos < Op)
					Opos++;
				else  // Opos > Op
					Opos--;
			}
			else {
				int Op = O.front().first;
				int Bp = B.front().first;

				if (O.front().second < B.front().second) {
					if (Opos == Op)
						O.pop();
					else if (Opos < Op)
						Opos++;
					else  // Opos > Op
						Opos--;

					if (Bpos < Bp)
						Bpos++;
					else if (Bpos > Bp)
						Bpos--;
				}
				else {
					if (Bpos == Bp)
						B.pop();
					else if (Bpos < Bp)
						Bpos++;
					else  // Bpos > Bp
						Bpos--;

					if (Opos < Op)
						Opos++;
					else if (Opos > Op)
						Opos--;
				}
			}

			time++;
		}

		cout << '#' << t << ' ' << time << '\n';
	}

	return 0;
}