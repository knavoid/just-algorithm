#include <iostream>
#include <vector>
#include <cstring>
 
using namespace std;
 
int answer, N, v1, v2;
bool mat[100][100], visited[100];
 
void visit(int v) {
    if (v == 99) {
        answer = true;
        return;
    }
 
    for (int i = 0; i < 100; i++) {
        if (mat[v][i] && !visited[i]) {
            visited[i] = true;
            visit(i);
        }
    }
}
 
int main() {
 
    for (int tc = 1; tc <= 10; tc++) {
        // initialize
        answer = false;
        memset(mat, false, sizeof(mat));
        memset(visited, false, sizeof(visited));
        visited[0] = true;
 
        // input
        cin >> tc >> N;
        for (int i = 0; i < N; i++) {
            cin >> v1 >> v2;
            mat[v1][v2] = true;
        }
 
        // solution
        visit(0);
 
        // output
        cout << '#' << tc << ' ' << answer << '\n';
    }
 
    return 0;
}