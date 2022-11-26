#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {

    int suit_count = 0;
    vector<int> suit(n, 1);  // 1로 채워진 n개의 vector를 생성

    for (int i : lost) suit[i - 1]--;
    for (int i : reserve) suit[i - 1]++;

    for (int i = 0; i < suit.size(); i++)
    {
        if (suit[i] == 0)
        {
            if (i > 0 && suit[i - 1] > 1)  // 앞 친구에게 체육복을 빌리는 경우
            {
                suit[i - 1]--;
                suit[i]++;
            }
            else if (i < suit.size() - 1 && suit[i + 1] > 1)  // 뒷 친구에게 체육복을 빌리는 경우
            {
                suit[i + 1]--;
                suit[i]++;
            }
        }
    }

    for (int i = 0; i < suit.size(); i++)
    {
        if (suit[i] > 0) suit_count++;
    }

    return suit_count;
}