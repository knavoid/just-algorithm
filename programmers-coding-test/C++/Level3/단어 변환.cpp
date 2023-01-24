#include <string>
#include <vector>

using namespace std;

int cnt = 21e8;
int used[20];

bool isSimil(string s1, string s2)
{
	int count = 0;
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] != s2[i]) count++;
	}
	return (count == 1);
}

void dfs(int lev, string now, string target, vector<string> words)
{
	if (now == target && lev < cnt)
	{
		cnt = lev;
		return;
	}
	for (int i = 0; i < words.size(); i++)
	{
		if (used[i] == 0 && isSimil(words[i], now))
		{
			used[i] = 1;
			dfs(lev + 1, words[i], target, words);
			used[i] = 0;
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;

	dfs(0, begin, target, words);
    if (cnt == 21e8) answer = 0;
	else answer = cnt;

	return answer;
}