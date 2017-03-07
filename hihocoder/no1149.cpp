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

const int MOD = 100007;

int T;

int main() {
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		string str;
		cin >> str;
		int n = str.size();
		vector<vector<ll>> dp(n, vector<ll>(n, 0));
		for (int i = 0; i < n; i++) dp[i][i] = 1;
		for (int len = 1; len < n; len++) {
			for (int i = 0; i < n - len; i++) {
				int j = i + len;
				if (str[i] == str[j]) dp[i][j] = (dp[i][j - 1] + dp[i + 1][j] + 1) % MOD;
				else dp[i][j] = (dp[i][j - 1] + dp[i + 1][j] + MOD - dp[i + 1][j - 1]) % MOD;
			}
		}
		cout << "Case #" << tt << ": " << dp[0][n - 1] << endl;
	}

	return 0;
}