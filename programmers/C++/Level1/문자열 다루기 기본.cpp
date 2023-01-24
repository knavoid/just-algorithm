#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    
	int n = s.length();
    if (n != 4 && n != 6) return false;

	for (int i = 0; i < n; i++)
		if (!isdigit(s[i]))
			return false;

	return true;
}