#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {

	int TC;
	cin >> TC;

	for (int t = 1; t <= TC; t++) {
		int N, M, x, y, answer = 0;
		map<int, set<int>> edges;
		cin >> N >> M;

		for (int i = 0; i < M; i++) {
			cin >> x >> y;
			edges[x].insert(y);
		}

		for (int n = 1; n <= N; n++) {
			vector<int> dest(edges[n].begin(), edges[n].end());
			int len = dest.size();
			for (int i = 0; i < len - 1; i++) 
				for (int j = i + 1; j < len; j++) 
					if (edges[dest[i]].find(dest[j]) != edges[dest[i]].end())
						answer++;
		}

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}