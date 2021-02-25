#include <cmath>

using namespace std;

long long solution(int w, int h) {

    long long answer = (long long)w * (long long)h;

    for (double y = 0; y < h; y++)
    {
        double x1 = y * (double)w / (double)h;
        double x2 = (y + 1) * (double)w / (double)h;

        long long x3 = floor(x1);
        long long x4 = ceil(x2);

        answer -= (x4 - x3);
    }

    return answer;
}
