#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {

    // arr1 : x * y 배열  /  arr2 : y * z 배열
    int x = arr1.size();
    int y = arr2.size();
    int z = arr2[0].size();
    vector<vector<int>> answer;

    for (int i = 0; i < x; i++)
    {
        vector<int> tmp;
        for (int j = 0; j < z; j++)
        {
            int value = 0;
            for (int k = 0; k < y; k++)
            {
                value += arr1[i][k] * arr2[k][j];
            }
            tmp.push_back(value);
        }
        answer.push_back(tmp);
    }

    return answer;
}
