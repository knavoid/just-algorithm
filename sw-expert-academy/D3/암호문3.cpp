#include <iostream>
#include <vector>

using namespace std;

const int NODE_MAX = 5000;

struct Node
{
	int data;
	Node *next;
	Node(int data, Node *next) : data(data), next(next) {}
};

class LinkedList
{
	Node *head;
	Node *tail;
	int size;
	vector<Node *> nodes;

public:
	LinkedList() : head(nullptr), tail(nullptr), size(0)
	{
		nodes.assign(NODE_MAX, nullptr);
	}

	Node *getNewNode(int data, Node *next)
	{
		nodes[size] = new Node(data, next);
		return nodes[size++];
	}

	Node *getNode(int idx)
	{
		Node *cur = head;
		for (int i = 0; i < idx; i++)
		{
			cur = cur->next;
		}
		return cur;
	}

	void insert(int idx, const vector<int> &values)
	{
		Node *cur;
		if (idx == 0)
		{
			cur = head = getNewNode(values[0], head);
			for (int i = 1; i < values.size(); i++)
			{
				cur = cur->next = getNewNode(values[i], cur->next);
			}
		}
		else
		{
			cur = getNode(idx - 1);
			for (int i = 0; i < values.size(); i++)
			{
				cur = cur->next = getNewNode(values[i], cur->next);
			}
		}
		if (cur->next == nullptr)
		{
			tail = cur;
		}
	}

	void remove(int idx, int cnt)
	{
		if (idx == 0)
		{
			head = getNode(cnt);
		}
		else
		{
			getNode(idx - 1)->next = getNode(idx + cnt);
		}
	}

	void add(const vector<int> &values)
	{
		for (int i = 0; i < values.size(); i++)
		{
			tail = tail->next = getNewNode(values[i], nullptr);
		}
	}

	void print(int tc)
	{
		cout << '#' << tc << ' ';
		Node *cur = head;
		for (int i = 0; i < 10; i++)
		{
			cout << cur->data << ' ';
			cur = cur->next;
		}
		cout << '\n';
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int tc = 1; tc <= 10; tc++)
	{
		int N, M;
		int x, y;
		char cmd;
		vector<int> values;
		LinkedList list;

		cin >> N;
		values.resize(N);
		for (int i = 0; i < N; i++)
		{
			cin >> values[i];
		}
		list.insert(0, values);

		cin >> M;
		for (int i = 0; i < M; i++)
		{
			cin >> cmd;
			switch (cmd)
			{
			case 'I':
				cin >> x >> y;
				values.resize(y);
				for (int i = 0; i < y; i++)
				{
					cin >> values[i];
				}
				list.insert(x, values);
				break;
			case 'D':
				cin >> x >> y;
				list.remove(x, y);
				break;
			case 'A':
				cin >> y;
				values.resize(y);
				for (int i = 0; i < y; i++)
				{
					cin >> values[i];
				}
				list.add(values);
				break;
			}
		}
		list.print(tc);
	}

	return 0;
}