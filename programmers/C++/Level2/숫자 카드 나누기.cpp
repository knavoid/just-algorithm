#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int GCD(int a, int b) {
	return b ? GCD(b, a % b) : a;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
	int answer = 0;

	int indexA = 0;
	vector<int> qA = arrayA;
	while (indexA != qA.size() - 1) {
		qA.push_back(GCD(qA[indexA], qA[indexA + 1]));
		indexA += 2;
	}

	int indexB = 0;
	vector<int> qB = arrayB;
	while (indexB != qB.size() - 1) {
		qB.push_back(GCD(qB[indexB], qB[indexB + 1]));
		indexB += 2;
	}

	int A = qA[indexA]; // arrayA의 최대공약수
	int B = qB[indexB]; // arrayB의 최대공약수

	if (all_of(arrayB.begin(), arrayB.end(), [&](int x) { return x % A; }))
		answer = max(A, answer);
	if (all_of(arrayA.begin(), arrayA.end(), [&](int x) { return x % B; }))
		answer = max(B, answer);

	return answer;
}

int main() {
	cout << solution({ 14, 35, 119 }, { 18, 30, 102 });
	return 0;
}