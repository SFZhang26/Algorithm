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
	vector<vector<ll>> dist(n, vector<ll>(n, LARGE));
	vector<ll> cur(n, LARGE);
	for (int i = 0; i < m; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		dist[u - 1][v - 1] = myMin(dist[u - 1][v - 1], d);
		dist[v - 1][u - 1] = myMin(dist[v - 1][u - 1], d);
	}
	int node = s-1;
	vector<int> already;
	already.push_back(node);
	cur[node] = 0;
	while (true) {
		int next = -1;
		int len = LARGE;
		for (int i = 0; i < already.size(); i++) {
			for (int j = 0; j < n; j++) {
				if (already[i] == j) continue;
				if (dist[already[i]][j] < LARGE && cur[j] == LARGE) {
					int temp = cur[already[i]] + dist[already[i]][j];
					if (temp < len) {
						len = temp;
						next = j;
					}
				}
			}
		}
		if (next == (e - 1)) {
			cout << len << endl;
			break;
		}
		already.push_back(next);
		cur[next] = len;
	}
		
	return 0;
}