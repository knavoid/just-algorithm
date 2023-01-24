#include <iostream>
#include <string>

using namespace std;

string minNumber(string N) {

	int len = N.length();
	int idx = N.find_first_not_of('0', 1);

	if (idx == string::npos)
		return N;

	for (int i = idx + 1; i < len; i++)
		if (N[i] != '0' && N[i] <= N[idx])
			idx = i;

	if (N[0] > N[idx]) {
		swap(N[0], N[idx]);
		return N;
	}

	for (int i = 1; i < len - 1; i++) {
		int minIndex = i + 1;
		for (int j = i + 2; j < len; j++) 
			if (N[j] <= N[minIndex])
				minIndex = j;

		if (N[i] > N[minIndex]) {
			swap(N[i], N[minIndex]);
			break;
		}
	}

	return N;
}

string maxNumber(string N) {

	int len = N.length();

	for (int i = 0; i < len - 1; i++) {
		int maxIndex = i + 1;
		for (int j = i + 2; j < len; j++)
			if (N[j] >= N[maxIndex])
				maxIndex = j;

		if (N[i] < N[maxIndex]) {
			swap(N[i], N[maxIndex]);
			break;
		}
	}

	return N;
}

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		string N;
		cin >> N;

		cout << '#' << t << ' ' << minNumber(N) << ' ' << maxNumber(N) << '\n';
	}

	return 0;
}