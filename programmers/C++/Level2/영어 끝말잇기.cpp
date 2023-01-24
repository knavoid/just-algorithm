#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {

	int len = words.size();
	unordered_map<string, int> hmap;

	for (int i = 0; i < len; i++)
	{
		if (i > 0 && words.at(i).at(0) != words.at(i - 1).at(words.at(i - 1).length() - 1)) return { i % n + 1, i / n + 1 };
		else if (hmap.count(words.at(i))) return { i % n + 1, i / n + 1 };
		else hmap[words.at(i)]++;
	}

	return vector<int>(2, 0);
}
