#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
int main() {
 
    int T;
    cin >> T;
 
    for (int tc = 1; tc <= T; tc++) {
        int N, answer = 0;
        cin >> N;
 
        vector<string> crops(N);
        for (int i = 0; i < N; i++)
            cin >> crops[i];
 
        int n = N / 2;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                // 좌표의 합이 n이상 3n이하, 두 좌표의 차가 n이하
                if (n <= i + j && i + j <= 3 * n && abs(i - j) <= n)
                    answer += crops[i][j] - '0';
 
        cout << '#' << tc << ' ' << answer << '\n';
    }
 
    return 0;
}