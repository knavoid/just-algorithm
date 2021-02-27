#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {

    int h_index = 0;

    sort(citations.begin(), citations.end());

    for (int h = 1; h <= citations.size(); h++)
    {
        int inyong = 0;
        for (int i = 0; i < citations.size(); i++)
        {
            if (citations.at(i) >= h)
            {
                inyong = citations.size() - i;
                break;
            }
        }
        if (inyong >= h) h_index = h;
    }

    return h_index;
}
