#include <iostream>
#include <climits>
#include <algorithm>
 
#define N 100
 
using namespace std;
 
int answer;
int ladder[N][N];
 
int main() {
 
    for (int tc = 1; tc <= 10; tc++) {
        // input
        cin >> tc;
        for (int i = 0; i < N; i++) 
            for (int j = 0; j < N; j++) 
                cin >> ladder[i][j];
 
        // solution
        int minDist = INT_MAX;
        for (int yy = 0; yy < N; yy++) {
            if (ladder[0][yy] == 1) {
                int dist = 0, y = yy;
                for (int x = 0; x < N; x++) {
                    // 왼쪽으로 갈 수 있는 경우
                    if (y != 0 && ladder[x][y - 1] == 1) {
                        while (y > 0 && ladder[x][y - 1] == 1) {
                            y--;
                            dist++;
                        }
                    }
                    // 오른쪽으로 갈 수 있는 경우
                    else if (y != N - 1 && ladder[x][y + 1] == 1) {
                        while (y < N - 1 && ladder[x][y + 1] == 1) {
                            y++;
                            dist++;
                        }
                    }
                }
                if (dist <= minDist) {
                    minDist = dist;
                    answer = yy;
                }
            }
        }
 
        // output
        cout << '#' << tc << ' ' << answer << '\n';
    }
}