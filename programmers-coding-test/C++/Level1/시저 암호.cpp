#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    
    for (int x = 0; x < n; x++)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (isalpha(s[i]))
            {
                if (s[i] == 'z'|| s[i] == 'Z') s[i] -= 25;
                else s[i]++;   
            }
        }
    }    

    return s;
}