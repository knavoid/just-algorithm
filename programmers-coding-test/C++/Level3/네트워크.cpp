#include <string>
#include <vector>

using namespace std;

void network(int now, vector<vector<int>> computers, vector<bool>& visited) {
	
	visited[now] = true;

	for (int i = 0; i < computers.size(); i++)
		if (i != now && computers[now][i] == 1 && visited[i] == false)
			network(i, computers, visited);
}

int solution(int n, vector<vector<int>> computers) {

	int answer = 0;
	vector<bool> visited(n, false);

	for (int i = 0; i < n; i++)
	{
		if (visited[i] == false)
		{
			network(i, computers, visited);
			answer++;
		}
	}

	return answer;
}
