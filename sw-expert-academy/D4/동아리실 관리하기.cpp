#include <iostream>
#include <string>
 
using namespace std;
 
int T;
string incharge;
int cases[10000][16];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // initialize
        cin >> incharge;
        fill(cases[0], cases[10000], 0);
 
        // solution
        int b = 1 | (1 << (incharge[0] - 'A'));
        for (int i = 1; i < 16; i++) {
            if ((i & b) == b) {
                cases[0][i] = 1;
            }
        }
        for (int i = 1; i < incharge.length(); i++) {
            for (int j = 1; j < 16; j++) {
                if ((j & (1 << (incharge[i] - 'A'))) != 0) {
                    for (int k = 1; k < 16; k++) {
                        if ((j & k) != 0) {
                            cases[i][j]= (cases[i][j] + cases[i - 1][k]) % 1000000007;
                        }
                    }
                }
            }
        }
 
        // result
        int answer = 0;
        for (int i = 1; i < 16; i++) {
            answer = (answer + cases[incharge.length() - 1][i]) % 1000000007;
        }
        cout << '#' << tc << ' ' << answer << '\n';
    }
 
    return 0;
}