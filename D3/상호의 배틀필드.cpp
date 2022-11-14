#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct direct {
	char mark;
	int dx, dy;
};

unordered_map<char, direct> D = {
	{'U', {'^', -1,  0}}, {'^', {' ', -1,  0}},
	{'D', {'v',  1,  0}}, {'v', {' ',  1,  0}},
	{'L', {'<',  0, -1}}, {'<', {' ',  0, -1}},
	{'R', {'>',  0,  1}}, {'>', {' ',  0,  1}}
};

bool inRange(int H, int W, int x, int y) {
	return 0 <= x && x < H && 0 <= y && y < W;
}

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int H, W, N;
		string cmd;
		cin >> H >> W;

		// 맵 입력
		vector<string> map(H);
		for (int i = 0; i < H; i++)
			cin >> map[i];

		// 동작 입력
		cin >> N >> cmd;

		// 전차 위치 찾기
		int x, y;
		for (int i = 0; i < H; i++) {
			int j = map[i].find_first_of("^v<>");
			if (j != string::npos) {
				x = i;
				y = j;
				break;
			}
		}

		// 동작 수행
		for (char c : cmd) {

			if (c != 'S') { // 이동
				// 전차 마크 변경
				map[x][y] = D[c].mark;

				// 이동 방향이 맵을 벗어나지 않으며, 평지인 경우 이동
				int dx = x + D[c].dx;
				int dy = y + D[c].dy;
				if (inRange(H, W, dx, dy) && map[dx][dy] == '.') {
					swap(map[x][y], map[dx][dy]);
					x = dx;
					y = dy;
				}
			}
			else { // 공격
				char mark = map[x][y];
				int sx = x, sy = y; // 포탄 좌표
				int dsx = D[mark].dx, dsy = D[mark].dy; // 포탄 이동 방향

				// 벽, 강철을 만나거나 맵 밖으로 벗어날 때까지 이동
				while (inRange(H, W, sx, sy) && map[sx][sy] != '*' && map[sx][sy] != '#') {
					sx += dsx;
					sy += dsy;
				}

				// 만약 벽을 만난 경우 파괴
				if (inRange(H, W, sx, sy) && map[sx][sy] == '*')
					map[sx][sy] = '.';
			}
		}

		// 현재 맵 상태 출력
		cout << '#' << tc << ' ';
		for (string m : map)
			cout << m << '\n';
	}

	return 0;
}