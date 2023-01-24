#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {

    // 1단계
    for (int i = 0; i < new_id.length(); i++)
    {
        if (new_id[i] >= 'A' && new_id[i] <= 'Z')
            new_id[i] += 32;  // 대문자일 경우 소문자로 변경
    }

    // 2단계
    for (int i = 0; i < new_id.length(); i++)
    {
        int ch = new_id[i];
        if (ch >= 'a' && ch <= 'z') continue;
        if (ch >= '0' && ch <= '9') continue;
        if (ch == '-' || ch == '_' || ch == '.') continue;

        new_id.erase(i--, 1);
    }

    // 3단계
    for (int i = 0; i < new_id.length() - 1; i++)
    {
        if (new_id[i] == '.' && new_id[i + 1] == '.')
            new_id.erase(i--, 1);
    }

    // 4단계
    int n = new_id.length();
    if (new_id[n - 1] == '.') new_id.erase(n - 1, 1);
    if (new_id[0] == '.') new_id.erase(0, 1);

    // 5단계
    if (new_id == "") new_id = "a";

    // 6단계
    if (new_id.length() > 15)
    {
        new_id = new_id.substr(0, 15);
        if (new_id[14] == '.') new_id.erase(14, 1);
    }

    // 7단계
    while (new_id.length() <= 2)
    {
        int n = new_id.length();
        new_id = new_id + new_id[n - 1];
    }

    return new_id;
}