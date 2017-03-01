#include <iostream>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
#include <bitset>
#include <functional>

using namespace std;

typedef long long ll;

int T;

int main() {
	//open files
	ifstream f_input;
	ofstream f_output;

	f_input.open("B-large-practice.in");
	f_output.open("out_put");

	f_input >> T;

	for (int tt = 1; tt <= T; tt++) {
		int m, n;
		f_input >> m >> n;
		vector<vector<int>> island(m, vector<int>(n, 0));
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
		int roof = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int cur;
				f_input >> cur;
				//cout << cur << " ";
				island[i][j] = cur;

				if (!(i == 0 || i == m - 1 || j == 0 || j == n - 1)) continue;
				que.push(make_pair(island[i][j], i*n + j));
				visited[i][j] = true;
			}
			//cout << endl;
		}
		ll result = 0;
		vector<vector<int>> direction{ { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
		while (!que.empty()) {
			pair<int, int> cur = que.top();
			que.pop();
			int height = cur.first;
			roof = max(roof, height);
			int i = cur.second / n, j = cur.second%n;
			for (int k = 0; k < 4; k++) {
				int i2 = i + direction[k][0], j2 = j + direction[k][1];
				if (i2 < 0 || i2 >= m || j2 < 0 || j2 >= n || visited[i2][j2]) continue;
				visited[i2][j2] = true;
				if (island[i2][j2] < roof) result += (roof - island[i2][j2]);
				que.push(make_pair(island[i2][j2], i2*n + j2));
			}
		}
		f_output <<"Case #"<<tt<<": "<< result << endl;
		cout << tt << " finished" << endl;
	}

	f_input.close();
	f_output.close();
}