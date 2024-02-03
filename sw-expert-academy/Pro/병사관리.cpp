#include <algorithm>

using namespace std;

const int ID_MIN = 1;
const int ID_MAX = 100000;
const int TEAM_MIN = 1;
const int TEAM_MAX = 5;
const int SCORE_MIN = 1;
const int SCORE_MAX = 5;

struct Node {
	int id;
	int team;
	Node* prev;
	Node* next;
};

class List {
	Node* head = new Node();
	Node* tail = new Node();

public:
	void initialize() {
		head->next = tail;
		tail->prev = head;
	}

	bool isEmpty() {
		return head->next == tail;
	}

	void insert(Node* node) {
		tail->prev->next = node;
		node->prev = tail->prev;
		node->next = tail;
		tail->prev = node;
	}

	static void erase(Node* node) {
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}

	void merge(List list) {
		if (!list.isEmpty()) {
			tail->prev->next = list.head->next;
			list.head->next->prev = tail->prev;
			list.tail->prev->next = tail;
			tail->prev = list.tail->prev;
			list.initialize();
		}
	}

	int getMaxID() {
		int maxID = 0;
		for (Node* cur = head->next; cur != tail; cur = cur->next) {
			maxID = max(maxID, cur->id);
		}
		return maxID;
	}

};

Node soldiers[ID_MAX + 1];
List sGroup[TEAM_MAX + 1][SCORE_MAX + 1];

void init() {
	for (int i = TEAM_MIN; i <= TEAM_MAX; i++) {
		for (int j = SCORE_MIN; j <= SCORE_MAX; j++) {
			sGroup[i][j].initialize();
		}
	}
}

void hire(int mID, int mTeam, int mScore) {
	soldiers[mID] = { mID, mTeam, nullptr, nullptr };
	sGroup[mTeam][mScore].insert(soldiers + mID);
}

void fire(int mID) {
	List::erase(soldiers + mID);
}

void updateSoldier(int mID, int mScore) {
	List::erase(soldiers + mID);
	sGroup[soldiers[mID].team][mScore].insert(soldiers + mID);
}

void updateTeam(int mTeam, int mChangeScore) {
	if (mChangeScore > 0) {
		for (int mScore = SCORE_MAX - 1; mScore >= SCORE_MIN; mScore--) {
			sGroup[mTeam][min(mScore + mChangeScore, SCORE_MAX)].merge(sGroup[mTeam][mScore]);
		}
	}
	else if (mChangeScore < 0) {
		for (int mScore = SCORE_MIN + 1; mScore <= SCORE_MAX; mScore++) {
			sGroup[mTeam][max(mScore + mChangeScore, SCORE_MIN)].merge(sGroup[mTeam][mScore]);
		}
	}
}

int bestSoldier(int mTeam) {
	for (int mScore = SCORE_MAX; mScore >= SCORE_MIN; mScore--) {
		if (!sGroup[mTeam][mScore].isEmpty()) {
			return sGroup[mTeam][mScore].getMaxID();
		}
	}
	return -1;
}