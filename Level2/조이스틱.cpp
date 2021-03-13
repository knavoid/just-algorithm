#include <string>
#include <vector>

using namespace std;

int solution(string name) {

    int answer = 0;
    int len = name.length();
    int min_range = len - 1;
    
    for (char c : name)
        answer += min(c - 'A', 'Z' + 1 - c);

    for (int i = 0; i < len; i++) 
    {
        int j = i + 1;  // i보다 크며, 해당 위치가 A가 아닌 index
        while (j < len && name[j] == 'A') j++;

        int left = len - j;  // 커서(0) 기준 왼쪽 범위
        int right = i;  // 커서(0) 기준 오른쪽 범위
        int range = min(left, right) + left + right;

        min_range = min(min_range, range);
    }

    answer += min_range;

    return answer;
}
