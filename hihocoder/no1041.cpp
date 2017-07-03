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

bool flag;
int T, n, a, b, m, ind;
int order[MAX];
bool g[MAX][MAX];
bitset<MAX> dig[MAX];
vector<int> edge[MAX];

void build(int root, int old) {
	dig[root][root] = 1;
	for (int i = 0; i < edge[root].size(); i++) {
		int cur = edge[root][i];
		if (cur == old) continue;
		build(cur, root);
		dig[root] |= dig[cur];
	}
}

void dfs(int cur, int old) {
	if (cur == order[ind]) {
		ind++;
	}
	if (ind == m) {
		flag = true;
		return;
	}
	while (ind < m) {
		int save = ind, dest = order[ind];
		for (int i = 0; i < edge[cur].size(); i++) {
			int next = edge[cur][i];
			if (next == old) continue;
			if (g[cur][next] && dig[next][dest]) {
				g[cur][next] = false;
				dfs(next, cur);
				break;
			}
		}
		if (save == ind) break;
	}
}

int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		flag = false;
		ind = 0;
		for (int i = 0; i < MAX; i++) {
			edge[i] = vector<int>();
			dig[i].reset();
			for (int j = 0; j < MAX; j++) {
				g[i][j] = false;
			}
		}
		scanf("%d", &n);
		for (int i = 1; i < n; i++) {
			scanf("%d %d", &a, &b);
			edge[a].push_back(b);
			edge[b].push_back(a);
			g[a][b] = true;
			g[b][a] = true;
		}
		build(1, -1);
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%d", &order[i]);
		}
		dfs(1, -1);
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}