#include <iostream>

using namespace std;

struct Node {
	int value;
	Node* prev;
	Node* next;
	Node(int value, Node* prev, Node* next) {
		this->value = value;
		this->prev = prev;
		this->next = next;
	}
};

int T;
int N, M, L;
Node* head;
Node* tail;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		// initialize
		head = tail = NULL;
		cin >> N >> M >> L;
		while (N--) {
			int number;
			cin >> number;
			if (head == NULL) {
				head = new Node(number, NULL, NULL);
				tail = head;
			}
			else {
				tail->next = new Node(number, tail, NULL);
				tail = tail->next;
			}
		}

		// solution
		for (int i = 0; i < M; i++) {
			char cmd;
			int index, number;
			Node* cur = head;
			cin >> cmd >> index;
			if (cmd == 'I') {
				cin >> number;
				index--;
				if (index == -1) {
					if (head == NULL) {
						head = new Node(number, NULL, NULL);
						tail = head;
					}
					else {
						Node* node = new Node(number, NULL, head);
						head->prev = node;
						head = node;
					}
				}
				else {
					while (index--) cur = cur->next;
					Node* node = new Node(number, cur, cur->next);
					if (cur != tail) {
						cur->next->prev = node;
						cur->next = node;
					}
					else {
						cur->next = node;
						tail = node;
					}
				}
			}
			else if (cmd == 'D') {
				while (index--) cur = cur->next;
				if (cur->prev) {
					cur->prev->next = cur->next;
				}
				if (cur->next) {
					cur->next->prev = cur->prev;
				}
				if (cur == head) {
					head = cur->next;
				}
				if (cur == tail) {
					tail = cur->prev;
				}
			}
			else if (cmd == 'C') {
				cin >> number;
				while (index--) cur = cur->next;
				cur->value = number;
			}
		}

		// result
		Node* cur = head;
		while (L-- && cur) {
			cur = cur->next;
		}
		int answer = cur ? cur->value : -1;
		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}