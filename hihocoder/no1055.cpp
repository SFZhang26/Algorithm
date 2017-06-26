#include <cstdio>
#include <cstring>
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

const int MAX = 101;

vector<int> edge[MAX];
int dp[MAX][MAX];
int val[MAX];
bool visited[MAX];
int N, M, u, v;

void dfs(int n) {
	visited[n] = true;
	dp[n][1] = val[n];
	for (int i = 0; i < edge[n].size(); i++) {
		int cur = edge[n][i];
		if (visited[cur]) continue;
		dfs(cur);
		for (int m = M; m >= 2; m--) {
			for (int k = 1; k < m; k++) {
				dp[n][m] = max(dp[n][m], dp[n][m - k] + dp[cur][k]);
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < MAX; i++) visited[i] = false;
	for (int i = 1; i <= N; i++) cin >> val[i];
	for (int i = 1; i < N; i++) {
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1);
	cout << dp[1][M] << endl;
	return 0;
}