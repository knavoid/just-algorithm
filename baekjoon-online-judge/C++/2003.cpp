#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int value; cin >> value;
		arr.push_back(value);
	}
}

int getSum(int x, int y)
{
	int sum = 0;
	for (int i = x; i < y; i++)
	{
		sum += arr[i];
	}
	return sum;
}

int main()
{
	input();

	int cnt = 0;
	int start = 0, end = 0;

	while (start < arr.size())
	{
		int sum = getSum(start, end);
		if (sum == M) cnt++;

		if (sum <= M && end < arr.size()) end++;
		else start++;
	}

	cout << cnt;

	return 0;
}