#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int solution(int N, vector<double> income) {
	double avg = accumulate(income.begin(), income.end(), 0) / N;
	return count_if(income.begin(), income.end(), [&](double x) { return x <= avg; });
}

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;

		vector<double> income(N);
		for (int i = 0; i < N; i++)
			cin >> income[i];

		cout << '#' << t << ' ' << solution(N, income) << '\n';
	}

	return 0;
}