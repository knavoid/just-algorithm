#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
	int p_count = 0;
	int y_count = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'p' || s[i] == 'P') p_count++;
		if (s[i] == 'y' || s[i] == 'Y') y_count++;
	}

    return p_count == y_count ? true : false;
}