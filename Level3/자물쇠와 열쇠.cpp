#include <string>
#include <vector>

using namespace std;

bool check(int start, int locksize, vector<vector<int>> map) {
	for (int i = start; i < start + locksize; i++) {
		for (int j = start; j < start + locksize; j++) {
			if (map[i][j] != 1) return false;
		}
	}
	return true;
}

bool correct(int keysize, int mapsize, int locksize, vector<vector<int>> key, vector<vector<int>> map) {
	for (int i = 0; i < mapsize - keysize + 1; i++) {
		for (int j = 0; j < mapsize - keysize + 1; j++) {
			vector<vector<int>> tmp = map;
			for (int k = 0; k < keysize; k++) {
				for (int l = 0; l < keysize; l++) {
					tmp[i + k][j + l] += key[k][l];
				}
			}
			if (check(keysize - 1, locksize, tmp)) return true;
		}
	}
	return false;
}

// 2차 배열을 시계방향으로 회전
void spin(int n, vector<vector<int>>& arr) {
	vector<vector<int>> tmp = arr;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = tmp[n - j - 1][i];
		}
	}
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {

	bool answer = false;
	int keysize = key.size();
	int locksize = lock.size();
	int mapsize = 2 * keysize + locksize - 2;
	vector<vector<int>> map(mapsize, vector<int>(mapsize, 0));

	// key, lock을 이용하여 큰 map을 구성
	for (int i = 0; i < locksize; i++) {
		for (int j = 0; j < locksize; j++)
		{
			map[i + keysize - 1][j + keysize - 1] = lock[i][j];
		}
	}

	// key를 회전하며 검사
	for (int i = 0; i < 4; i++) {
		if (correct(keysize, mapsize, locksize, key, map)) {
			answer = true;
			break;
		}
		spin(keysize, key);
	}

	return answer;
}
