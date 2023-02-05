#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> numbers;

bool comp(int n1, int n2) {
	return to_string(n1) + to_string(n2) > to_string(n2) + to_string(n1);
}

int main() {
	// initialize
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		int number; cin >> number;
		numbers.push_back(number);
	}

	// 가장 큰 수를 (N-K)개 추가
	int maxValue = *max_element(numbers.begin(), numbers.end());
	for (int i = 0; i < N - K; i++) {
		numbers.push_back(maxValue);
	}

	// 조건에 알맞게 정렬
	sort(numbers.begin(), numbers.end(), comp);

	// result
	for (int n : numbers) {
		cout << to_string(n);
	}

	return 0;
}