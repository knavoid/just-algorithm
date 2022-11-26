#include <string>
#include <vector>

using namespace std;

string getBinary(int n, int len)
{
    string binary = "";
    for (int i = 0; i < len; i++)
    {
        binary = to_string(n % 2) + binary;
        n /= 2;
    }

    return binary;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {

    vector<string> answer;

    vector<string> map1;
    vector<string> map2;

    // 지도 해독
    for (int i : arr1) map1.push_back(getBinary(i, n));
    for (int i : arr2) map2.push_back(getBinary(i, n));

    for (int i = 0; i < n; i++)
    {
        string s = "";
        for (int j = 0; j < n; j++)
        {
            if (map1[i][j] == '0' && map2[i][j] == '0') s.append(" ");
            else s.append("#");
        }
        answer.push_back(s);
    }

    return answer;
}
