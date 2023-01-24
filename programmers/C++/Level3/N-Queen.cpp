#include <string>
#include <vector>

using namespace std;

vector<pair<int, int>> points;

bool possible(int row, int col) {

    for (pair<int, int> p : points) {
        int row_gap = abs(row - p.first);
        int col_gap = abs(col - p.second);
        if (row == p.first) return false;  // Queen이 같은 행에 있는 경우
        if (col == p.second) return false;  // Queen이 같은 열에 있는 경우
        if (abs(row - p.first) == abs(col - p.second)) return false;  // Queen이 대각선상에 있는 경우
    }

    return true;
}

void nQueens(int row, int n, int& answer) {

    if (row == n) {
        answer++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (possible(row, col)) {
            points.push_back({ row, col });
            nQueens(row + 1, n, answer);
            points.pop_back();
        }
    }
}

int solution(int n) {

    int answer = 0;
    nQueens(0, n, answer);

    return answer;
}
