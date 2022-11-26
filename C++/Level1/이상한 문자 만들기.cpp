#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    
    bool even = true;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ') even = false;
        else if (even && s[i] >= 'a' && s[i] <= 'z') s[i] = toupper(s[i]);
        else if (!even && s[i] >= 'A' && s[i] <= 'Z') s[i] = tolower(s[i]);
        
        even = even ? false : true;
    }

    return s;
}