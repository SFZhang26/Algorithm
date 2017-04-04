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
int n, m;

int main() {
	cin >> T;
	for (int tt = 0; tt < T; tt++) {
		cin >> n >> m;
		int SIZE = (1 << m);
		vector<vector<int>> dp(n + 1, vector<int>(SIZE * 2, -1));
		dp[0][0] = 0;
		for (int i = 1; i <= n; i++) {
			int v, s;
			cin >> v >> s;
			int mask = 0;
			for (int j = 0; j < s; j++) {
				int pos;
				cin >> pos;
				mask |= (1 << (pos - 1));
			}
			for (int j = 0; j < SIZE; j++) {
				if (dp[i - 1][j]>-1) {
					dp[i][j^mask] = max(dp[i][j^mask], dp[i - 1][j] + v);
					dp[i][j] = max(dp[i][j], dp[i - 1][j]);
				}
			}
		}
		cout << max(dp[n][SIZE - 1], 0) << endl;
	}
	return 0;
}