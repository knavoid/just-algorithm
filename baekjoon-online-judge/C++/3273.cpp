#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, x;
vector<int> numbers;
int answer;

int main() {
	// initialize
	cin >> n;
	numbers.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	cin >> x;

	// 오름차순 정렬
	sort(numbers.begin(), numbers.end());

	// 두 포인터가 만날때까지 반복
	int point1 = 0, point2 = n - 1;
	while (point1 < point2) {
		int n1 = numbers[point1];
		int n2 = numbers[point2];
		int sum = n1 + n2;
		// 포인트 이동
		if (sum < x) {
			point1++;
		}
		else if (sum > x) {
			point2--;
		}
		else {
			point1++;
			point2--;
			answer++;
		}
	}

	// result
	cout << answer;

	return 0;
}