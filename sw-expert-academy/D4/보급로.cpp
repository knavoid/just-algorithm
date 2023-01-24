#include <iostream>
#include <queue>
#include <tuple>
#include <climits>
 
using namespace std;
 
int T, N;
int road[100][100], minTime[100][100];
int direct[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
 
bool inRange(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < N;
}
 
int main() {
 
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // input
        cin >> N;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                scanf("%1d", &road[i][j]);
 
        // solution
        int x, y, dx, dy;
        queue<pair<int, int>> pointq;
        pointq.push(make_pair(0, 0));
        fill(minTime[0], minTime[N], INT_MAX);
        minTime[0][0] = 0;
 
        while (!pointq.empty()) {
            x = pointq.front().first;
            y = pointq.front().second;
            pointq.pop();
 
            for (int d = 0; d < 4; d++) {
                dx = x + direct[d][0];
                dy = y + direct[d][1];
                if (inRange(dx, dy) && minTime[dx][dy] > minTime[x][y] + road[dx][dy]) {
                    minTime[dx][dy] = minTime[x][y] + road[dx][dy];
                    pointq.push(make_pair(dx, dy));
                }
            }
        }
 
        // output
        cout << '#' << tc << ' ' << minTime[N - 1][N - 1] << '\n';
    }
 
    return 0;
}