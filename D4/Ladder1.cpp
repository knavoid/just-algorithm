#include <iostream>
 
#define N 100
 
using namespace std;
 
int y; // 위치
int ladder[N][N];
 
int main() {
 
    for (int tc = 1; tc <= 10; tc++) {
        // input
        cin >> tc;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> ladder[i][j];
                if (i == N - 1 && ladder[i][j] == 2)
                    y = j;
            }
        }
 
        // solution
        for (int x = N - 1; x >= 0; x--) {
            // 왼쪽으로 갈 수 있는 경우
            if (y != 0 && ladder[x][y - 1] == 1)
                while (y > 0 && ladder[x][y - 1] == 1)
                    y--;
     
            // 오른쪽으로 갈 수 있는 경우
            else if (y != N - 1 && ladder[x][y + 1] == 1)
                while (y < N - 1 && ladder[x][y + 1] == 1)
                    y++;
        }
 
        // output
        cout << '#' << tc << ' ' << y << '\n';
    }
}