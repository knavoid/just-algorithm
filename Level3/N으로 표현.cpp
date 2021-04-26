#include <string>
#include <vector>

using namespace std;

int min_use = 9;

void dfs(int N, int number, int use, int value) {

    if (use > 8) return;  // 현재까지의 사용 횟수가 8보다 큰 경우

    if (value == number) {
        min_use = min(use, min_use);
        return;
    }

    int opr = 0;
    for (int i = 1; i <= 8; i++) {  // i : 피연산자의 자리수
        opr = opr * 10 + N;
        dfs(N, number, use + i, value + opr);
        dfs(N, number, use + i, value - opr);
        if (value == 0) continue;
        dfs(N, number, use + i, value * opr);
        dfs(N, number, use + i, value / opr);
    }
}

int solution(int N, int number) {

    dfs(N, number, 0, 0);

    return ((min_use <= 8) ? min_use : -1);
}
