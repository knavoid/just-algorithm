#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {

    int row = 0, col = 0, value = 1;
    vector<vector<int>> snail;
    vector<int> answer;

    for (int i = 1; i <= n; i++)
        snail.push_back(vector<int>(i, 0));

    for (int i = n; i > 0; i--)
    {
        int x = (n - i) % 3;
        for (int j = 0; j < i; j++)
        {
            snail[row][col] = value++;
            if (j < i - 1)
            {
                if (x == 0) row++;
                if (x == 1) col++;
                if (x == 2) { row--; col--; }
            }
            else
            {
                if (x == 0) col++;
                if (x == 1) { row--; col--; }
                if (x == 2) row++;
            }
        }
    }

    for (int i = 0; i < snail.size(); i++)
        for (int j = 0; j < snail[i].size(); j++)
            answer.push_back(snail[i][j]);

    return answer;
}
