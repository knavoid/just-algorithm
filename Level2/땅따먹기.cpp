#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land) {
    
    int n = land.size();
    
    for (int i = 0; i < n; i++)
    {
        if (i == 0) continue;
        for (int j = 0; j < 4; j++)
        {
            int max_value = 0;
            for (int k = 0; k < 4; k++)
            {
                if (k == j) continue;
                max_value = max(max_value, land[i - 1][k]);
            }
            land[i][j] += max_value;
        }
    }

    return *max_element(land[n - 1].begin(), land[n - 1].end());
}
