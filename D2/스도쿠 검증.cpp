#include <iostream>

using namespace std;

bool isValid(int sudoku[9][9]) {
	// 가로
	for (int i = 0; i < 9; i++) {
		bool check[10] = {};
		for (int j = 0; j < 9; j++) {
			int value = sudoku[i][j];
			if (check[value])
				return false;
			check[value] = true;
		}
	}

	// 세로
	for (int j = 0; j < 9; j++) {
		bool check[10] = {};
		for (int i = 0; i < 9; i++) {
			int value = sudoku[i][j];
			if (check[value])
				return false;
			check[value] = true;
		}
	}

	// 격자
	for (int r = 0; r < 9; r += 3) {
		for (int c = 0; c < 9; c += 3) {
			bool check[10] = {};
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					int value = sudoku[r + i][c + j];
					if (check[value])
						return false;
					check[value] = true;
				}
			}
		}
	}

	return true;
}

int main()
{
	int T;

	cin >> T;

	for (int t = 1; t <= T; t++) {
		int sudoku[9][9];

		// 입력
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> sudoku[i][j];
			}
		}

		// 검증 결과 출력
		cout << '#' << t << ' ' << isValid(sudoku) << '\n';
	}

	return 0;
}