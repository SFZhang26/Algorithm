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

using namespace std;

typedef long long ll;

int T;

bool solve(int N, int M, vector<vector<int>> graph) {
	vector<bool> visited(N + 1, false);
	vector<int> color(N + 1, 0);

	while (true) {
		int cur = 1;
		for (; cur < N + 1; cur++) {
			if (!visited[cur]) break;
		}
		if (cur == N + 1) break;
		color[cur] = 1;
		queue<int> que;
		que.push(cur);
		while (!que.empty()) {
			int now = que.front();
			visited[now] = true;
			que.pop();
			for (int j = 0; j < graph[now].size(); j++) {
				if (color[now] == color[graph[now][j]]) return false;
				color[graph[now][j]] = color[now] * (-1);
				if (!visited[graph[now][j]]) que.push(graph[now][j]);
			}
		}
	}
	return true;
}


int main() {
	int T;
	cin >> T;
	for (int tt = 0; tt < T; tt++) {
		int N, M;
		cin >> N >> M;

		vector<vector<int>> graph(N + 1, vector<int>());
		for (int i = 0; i < M; i++) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		bool result = solve(N, M, graph);
		if(result) cout << "Correct" << endl;
		else cout << "Wrong" << endl;
	}
	
	return 0;
}