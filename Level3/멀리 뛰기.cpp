long long solution(int n) {

    long long x = 1, y = 1;
    for (int i = 2; i <= n; i++) {
        long long tmp = y;
        y = (y + x) % 1234567;
        x = tmp;
    }

    return y;
}
