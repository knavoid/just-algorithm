#include <iostream>
#include <string>
#include <queue>
 
using namespace std;
 
int direct[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
 
int main() {
 
    for (int tc = 1; tc <= 10; tc++) {
        cin >> tc;
 
        int answer = 0;
        int sx = 0, sy = 0;
        string map[16];
        for (int i = 0; i < 16; i++) {
            cin >> map[i];
            int j = map[i].find('2');
            if (j != string::npos) {
                sx = i;
                sy = j;
            }
        }
 
        queue<pair<int, int>> points;
        bool visited[16][16] = { false };
        points.push(make_pair(sx, sy));
        visited[sx][sy] = true;
 
        while (!points.empty()) {
            int x = points.front().first;
            int y = points.front().second;
            if (map[x][y] == '3') {
                answer = 1;
                break;
            }
 
            points.pop();
            for (int d = 0; d < 4; d++) {
                int dx = x + direct[d][0];
                int dy = y + direct[d][1];
                if (map[dx][dy] != '1' && !visited[dx][dy]) {
                    points.push(make_pair(dx, dy));
                    visited[dx][dy] = true;
                }
            }
        }
 
        cout << '#' << tc << ' ' << answer << '\n';
    }
 
    return 0;
}