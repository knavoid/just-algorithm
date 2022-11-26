#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {

    int answer = 0;
    vector<int> basket;

    for (int i = 0; i < moves.size(); i++)
    {
        int grab = moves[i] - 1;
        for (int j = 0; j < board.size(); j++)
        {
            int value = board[j][grab];
            if (value != 0)  // board에서 인형 발견 시
            {
                board[j][grab] = 0;
                basket.push_back(value);

                int len = basket.size();
                if (len > 1 && basket[len - 2] == basket[len - 1])  // 바구니에 같은 인형이 만난 경우
                {
                    basket.pop_back();
                    basket.pop_back();
                    answer += 2;
                }

                break;
            }
        }
    }

    return answer;
}