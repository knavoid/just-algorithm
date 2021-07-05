#include <vector>

using namespace std;

// 구조물이 위치할 수 있는지 여부를 판단하는 함수
bool correct(int i, int j, int struc, vector<vector<int>> gidung, vector<vector<int>> bo) {
	if (struc == 0)  // 기둥
		if (j == 0 || (j > 0 && gidung[i][j - 1]) || bo[i][j] || (i > 0 && bo[i - 1][j]))
			return true;
	if (struc == 1)  // 보
		if ((j > 0 && (gidung[i][j - 1] || gidung[i + 1][j - 1])) || (i > 0 && bo[i - 1][j] && bo[i + 1][j]))
			return true;
	return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {

	vector<vector<int>> answer;
	vector<vector<int>> gidung(n + 1, vector<int>(n + 1, 0));  // 기둥을 표시
	vector<vector<int>> bo(n + 1, vector<int>(n + 1, 0));  // 보를 표시

	for (vector<int> frame : build_frame) {
		int x = frame[0], y = frame[1], a = frame[2], b = frame[3];
		if (b == 1) {  // 구조물 설치
			if (a == 0 && correct(x, y, a, gidung, bo))  // 해당 위치에 기둥이 위치할 수 있는지 판단
				gidung[x][y] = 1;
			if (a == 1 && correct(x, y, a, gidung, bo))  // 해당 위치에 보가 위치할 수 있는지 판단
				bo[x][y] = 1;
		}
		if (b == 0) {  // 구조물 삭제
			// 구조물을 삭제한다고 가정한 후, 관련된 주변 구조물이 안전한지 파악
			if (a == 0) {
				gidung[x][y] = 0;
				if (gidung[x][y + 1] && !correct(x, y + 1, 0, gidung, bo)) gidung[x][y] = 1;
				else if (x > 0 && bo[x - 1][y + 1] && !correct(x - 1, y + 1, 1, gidung, bo)) gidung[x][y] = 1;
				else if (bo[x][y + 1] && !correct(x, y + 1, 1, gidung, bo)) gidung[x][y] = 1;
			}
			if (a == 1) {
				bo[x][y] = 0;
				if (gidung[x][y] && !correct(x, y, 0, gidung, bo)) bo[x][y] = 1;
				else if (gidung[x + 1][y] && !correct(x + 1, y, 0, gidung, bo)) bo[x][y] = 1;
				else if (x > 0 && bo[x - 1][y] && !correct(x - 1, y, 1, gidung, bo)) bo[x][y] = 1;
				else if (bo[x + 1][y] && !correct(x + 1, y, 1, gidung, bo)) bo[x][y] = 1;
			}
		}
	}

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (gidung[i][j]) answer.push_back({ i, j, 0 });
			if (bo[i][j]) answer.push_back({ i, j, 1 });
		}
	}

	return answer;
}
