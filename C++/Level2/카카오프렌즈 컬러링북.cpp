#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int m, int n, vector<vector<int>> picture) {

    int number_of_area = 0;
    int max_size_of_one_area = 0;

    int direct[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    queue<pair<int, int>> same_color;

    for (int i = 0; i < picture.size(); i++)
    {
        for (int j = 0; j < picture[i].size(); j++)
        {
            if (picture[i][j] != 0)
            {
                int area = 1;
                int value = picture[i][j];

                picture[i][j] = 0;
                same_color.push({ i, j });

                while (!same_color.empty())
                {
                    int row = same_color.front().first;
                    int col = same_color.front().second;
                    same_color.pop();

                    for (int k = 0; k < 4; k++)
                    {
                        int drow = row + direct[k][0];
                        int dcol = col + direct[k][1];
                        if (drow >= 0 && drow < m && dcol >= 0 && dcol < n && picture[drow][dcol] == value)
                        {
                            picture[drow][dcol] = 0;
                            same_color.push({ drow, dcol });
                            area++;
                        }
                    }
                }

                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, area);
            }
        }
    }

    return { number_of_area, max_size_of_one_area };
}
