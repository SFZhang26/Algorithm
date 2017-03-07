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

int countOneBit(int a) {
	int result = 0;
	while (a) {
		result++;
		a &= (a - 1);
	}
	return result;
}

int main() {
	int n, m, Q;
	cin >> n >> m >> Q;
	vector<int> w(n, 0);
	for (int i = 0; i < n; i++) cin >> w[i];
	int size = pow(2, m);
	int mask = size - 1;
	vector<vector<int>> dp(n + 1, vector<int>(size, -1));
	for (int j = 0; j < size; j++) dp[0][j] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < size; j++) {
			if (dp[i - 1][j]>-1) {
				int a = (j << 1)&mask;
				int b = ((j << 1)&mask) + 1;
				dp[i][a] = max(dp[i][a], dp[i - 1][j]);
				if (countOneBit(b) <= Q) {
					dp[i][b] = max(dp[i][b], dp[i - 1][j] + w[i - 1]);
				}
			}
		}
	}
	int result = 0;
	for (int j = 0; j < size; j++) {
		result = max(result, dp[n][j]);
	}

	cout << result << endl;

	return 0;
}