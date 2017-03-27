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

int T;
int MOD = 142857;
const int SIZE = 100001;
bool visited[SIZE];
vector<int> sigToM[SIZE];
vector<int> mToSig[SIZE];
vector<int> que;
vector<int> signal;
int dp[SIZE] = {0};

void dfs(int cur) {
	if (visited[cur]) return;
	visited[cur] = true;
	for (int i = 0; i < mToSig[cur].size(); i++) {
		for (int j = 0; j < sigToM[mToSig[cur][i]].size(); j++) {
			dfs(sigToM[mToSig[cur][i]][j]);
		}
	}
	que.push_back(cur);
}


int main() {
	cin >> T;
	for (int tt = 0; tt < T; tt++) {
		int n, m;
		scanf("%d %d", &n, &m);
		signal.clear();
		que.clear();
		for (int i = 0; i < SIZE; i++) {
			visited[i] = false;
			dp[i] = 0;
		}
		for (int i = 0; i < SIZE; i++) {
			sigToM[i].clear();
			mToSig[i].clear();
		}
		for (int i = 0; i < m; i++) {
			int cur;
			scanf("%d", &cur);
			signal.push_back(cur);
		}
		for (int i = 0; i < n; i++) {
			int cur, num;
			scanf("%d %d", &cur, &num);
			sigToM[cur].push_back(i);
			for (int j = 0; j < num; j++) {
				int k;
				scanf("%d", &k);
				mToSig[i].push_back(k);
			}
		}
		for (int i = 0; i < n; i++) {
			dfs(i);
		}
		for (int i = 0; i < signal.size(); i++) {
			for (int j = 0; j < sigToM[signal[i]].size(); j++) {
				dp[sigToM[signal[i]][j]]++;
			}
		}
		for (int i = que.size() - 1; i >= 0; i--) {
			int cur = que[i];
			for (int j = 0; j < mToSig[cur].size(); j++) {
				for (int k = 0; k < sigToM[mToSig[cur][j]].size(); k++) {
					dp[sigToM[mToSig[cur][j]][k]] = (dp[sigToM[mToSig[cur][j]][k]] + dp[cur]) % MOD;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			cout << dp[i] << " ";
		}
		cout << endl;
	}
	
	return 0;
}