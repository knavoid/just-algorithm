#include <string>
#include <vector>

using namespace std;

// 특정 위치에서 거리두기가 잘 이루어지는지 판단
bool safeLocation(int row, int col, vector<string> place) {
	int dr1, dc1;  // 거리가 1인 좌표
	int dr2, dc2;  // 거리가 2인 좌표
	int direction[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

	for (int i = 0; i < 4; i++) {
		dr1 = row + direction[i][0];
		dc1 = col + direction[i][1];
		if (dr1 < 0 || dr1 > 4 || dc1 < 0 || dc1 > 4) continue;
		if (place[dr1][dc1] == 'P') return false;
		if (place[dr1][dc1] == 'O') {
			for (int j = 0; j < 4; j++) {
				dr2 = dr1 + direction[j][0];
				dc2 = dc1 + direction[j][1];
				if (dr2 < 0 || dr2 > 4 || dc2 < 0 || dc2 > 4) continue;
				if (dr2 == row && dc2 == col) continue;
				if (place[dr2][dc2] == 'P') return false;
			}
		}
	}
	return true;
}

// 특정 장소에서 거리두기가 잘 이루어지는지 판단
bool safePlace(vector<string> place) {
	for (int i = 0; i < place.size(); i++) {
		for (int j = 0; j < place[i].length(); j++) {
			if (place[i][j] == 'P') {
				if (!safeLocation(i, j, place)) {
					return false;
				}
			}
		}
	}
	return true;
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;

	for (vector<string> place : places) {
		if (safePlace(place)) answer.push_back(1);
		else answer.push_back(0);
	}

	return answer;
}
