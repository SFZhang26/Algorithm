#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <map>
#include <string>
#include <bitset>
#include <set>

using namespace std;

typedef long long ll;

int n, m;
vector<vector<int>> dire = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

int main() {
	cin >> n >> m;
	vector<string> grid(n, "");
	int count = 0;
	vector<vector<int>> result(n, vector<int>(m, -1));
	queue<pair<int, int>> que;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		grid[i] = temp;
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '0') {
				result[i][j] = 0;
				count++;
				que.push(make_pair(i, j));
			}
		}
	}

	while (!que.empty()) {
		pair<int, int> cur = que.front();
		que.pop();
		for (int k = 0; k < 4; k++) {
			int ii = cur.first + dire[k][0];
			int jj = cur.second + dire[k][1];
			if (ii < 0 || ii >= n || jj < 0 || jj >= m || result[ii][jj] != -1) continue;
			result[ii][jj] = result[cur.first][cur.second] + 1;
			que.push(make_pair(ii, jj));
			count++;
		}
		if (count == n*m) break;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}