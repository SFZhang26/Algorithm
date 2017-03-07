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

const int LARGE = 2147483647;

int T;

int n, m, s, e;

ll myMin(ll a, ll b) {
	return a > b ? b : a;
}

int main() {
	cin >> n >> m >> s >> e;
	s--;
	e--;
	vector<vector<ll>> dist(n, vector<ll>(n, LARGE));
	vector<ll> cur(n, LARGE);
	for (int i = 0; i < m; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		dist[u - 1][v - 1] = myMin(dist[u - 1][v - 1], d);
		dist[v - 1][u - 1] = myMin(dist[v - 1][u - 1], d);
	}
	vector<ll> dp(n, 0);
	vector<bool> used(n, false);
	for (int i = 0; i < n; i++) {
		dp[i] = dist[i][s];
	}
	dp[s] = 0;
	used[s] = true;
	for (int i = 0; i < n; i++) {
		int cur = -1;
		ll cur_max = LARGE;
		for (int j = 0; j < n; j++) {
			if (!used[j] && dp[j] < cur_max) {
				cur = j;
				cur_max = dp[j];
			}
		}
		used[cur] = true;
		if (cur == e) {
			cout << dp[e] << endl;
			break;
		}
		for (int j = 0; j < n; j++) {
			if (!used[j] && dist[cur][j]<LARGE) {
				dp[j] = myMin(dp[j], dp[cur] + dist[cur][j]);
			}
		}

	}
		
	return 0;
}