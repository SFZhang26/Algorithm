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

int n, m;

ll myMin(ll a, ll b) {
	return a > b ? b : a;
}

int main() {
	cin >> n >> m;
	vector<vector<ll>> dist(n, vector<ll>(n, LARGE));
	for (int i = 0; i < m; i++) {
		int r, c, d;
		cin >> r >> c >> d;
		dist[r - 1][c - 1] = myMin(dist[r - 1][c - 1], d);
		dist[c - 1][r - 1] = myMin(dist[r - 1][c - 1], d);
	}
	for (int i = 0; i < n; i++) dist[i][i] = 0;

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = myMin(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}