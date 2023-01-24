#include <string>
#include <vector>

using namespace std;

int solution(int n) {

    int answer = 0;
    int begin = 1, end = 1, sum = 0;
    
    while (begin <= n + 1 && end <= n + 1)
    {
        if (sum < n)
        {
            sum += end++;
        }
        else
        {
            if (sum == n) answer++;
            sum -= begin++;
        }
    }

    return answer;
}
