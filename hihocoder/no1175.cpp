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

const int MOD = 142857;

int main() {
	ll result = 0;
	int N, M, K;
	cin >> N >> M >> K;
	vector<ll> virus(N + 1, 0);
	vector<int> indegree(N + 1, 0);
	vector<vector<int>> graph(N + 1, vector<int>());
	for (int i = 0; i < K; i++) {
		int node;
		cin >> node;
		virus[node]++;
	}
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		indegree[v]++;
	}
	queue<int> que;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) que.push(i);
	}
	while (!que.empty()) {
		int i = que.front();
		que.pop();
		result = (result + virus[i]) % MOD; // IMPORTANT!!!
		for (int j = 0; j < graph[i].size(); j++) {
			indegree[graph[i][j]]--;
			virus[graph[i][j]] = (virus[graph[i][j]] + virus[i]) % MOD;// IMPORTANT!!!
			if (indegree[graph[i][j]] == 0) que.push(graph[i][j]);
		}
	}
	cout << result << endl;

	return 0;
}