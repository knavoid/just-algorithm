#include <iostream>
#include <vector>

using namespace std;

struct vertex {
	string value;
	int left, right;
};

int answer;
int N, num;
vector<vertex> tree;

int main() {

	for (int tc = 1; tc <= 10; tc++) {
		// initialize
		answer = 1;
		cin >> N;
		tree.assign(N + 1, { "", 0, 0 });
		for (int v = 1; v <= N; v++) {
			cin >> num >> tree[num].value;
			// 자식 정점이 있는지 확인하여 입력
			if (num * 2 <= N)
				cin >> tree[num].left;
			if (num * 2 + 1 <= N)
				cin >> tree[num].right;
		}

		// solution
		for (int v = 1; v <= N; v++) {
			bool isOper = string("+-*/").find(tree[v].value) != string::npos;
			
			// 정점의 값이 연산자인데 자식 정점이 하나라도 없는 경우
			if (isOper && (!tree[v].left || !tree[v].right)) {
				answer = 0;
				break;
			}

			// 정점의 값이 연산자인데 자식 정점이 있는 경우
			if (!isOper && (tree[v].left && tree[v].right)) {
				answer = 0;
				break;
			}
		}

		// result
		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}