#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {

    int n = triangle.size();
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            int max_value = 0;
            if (j != 0) max_value = max(max_value, triangle[i - 1][j - 1]);
            if (j != triangle[i].size() - 1) max_value = max(max_value, triangle[i - 1][j]);
            triangle[i][j] += max_value;
        }
    }

    return *max_element(triangle[n - 1].begin(), triangle[n - 1].end());
}
