#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<int> numbers, string hand) {

    string answer = "";
    string key[4] = { "123", "456", "789", "*0#" };
    unordered_map<int, pair<int, int>> hmap;

    int left_row = 3, left_col = 0;
    int right_row = 3, right_col = 2;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 3; j++)
            if (isdigit(key[i][j])) hmap[key[i][j] - '0'] = { i, j };  // 숫자들의 좌표를 저장 

    for (int number : numbers)
    {
        // 눌러야 할 숫자의 좌표
        int key_row = hmap[number].first;  
        int key_col = hmap[number].second;

        // 각 손가락들과 키의 거리
        int left_dist = abs(left_row - key_row) + abs(left_col - key_col);
        int right_dist = abs(right_row - key_row) + abs(right_col - key_col);

        if (number == 1 || number == 4 || number == 7)
        {
            left_row = key_row;
            left_col = key_col;
            answer.append("L");
        }
        else if (number == 3 || number == 6 || number == 9)
        {
            right_row = key_row;
            right_col = key_col;
            answer.append("R");
        }
        else
        {
            if (left_dist < right_dist || (left_dist == right_dist && hand == "left"))
            {
                left_row = key_row;
                left_col = key_col;
                answer.append("L");
            }
            else
            {
                right_row = key_row;
                right_col = key_col;
                answer.append("R");
            }
        }
    }

    return answer;
}
