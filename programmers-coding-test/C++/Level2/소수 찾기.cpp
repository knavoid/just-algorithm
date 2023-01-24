#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, int> hmap;
vector<bool> used(7);

bool isPrime(int n) {

	if (n <= 1) return false;

	for (int i = 2; i <= n / 2; i++)
		if (n % i == 0) 
			return false;

	return true;
}

void dfs(int lev, string numbers, string result) {
	
	if (lev == numbers.length())
	{
		if (result != "" && isPrime(stoi(result))) hmap[stoi(result)]++;
		return;
	}

	dfs(lev + 1, numbers, result);
	
	for (int i = 0; i < numbers.length(); i++)
	{
		if (used.at(i) == true) continue;
		used.at(i) = true;
		dfs(lev + 1, numbers, result + numbers.at(i));
		used.at(i) = false;
	}
}

int solution(string numbers) {

	dfs(0, numbers, "");

	return hmap.size();
}
