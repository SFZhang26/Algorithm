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

const ll MOD = 1e9 + 7;

int T;

int n;

vector<ll> get() {
	vector<ll> vec(28,1);
	for (int i = 2; i < 28; i++) {
		vec[i] = vec[i - 1] + vec[i - 2];
	}
	return vec;
}

int main() {
	cin >> n;
	vector<int> nums(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	vector<ll> fibo=get();
	vector<vector<int>> dp(n + 1, vector<int>(28, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 28; j++) {
			dp[i][j] = dp[i - 1][j];
		}
		int index = 0;
		for (; index < 28; index++) if (fibo[index] == nums[i - 1]) break;
		if (index < 28) {
			if (fibo[index] == 1) {
				dp[i][index + 1] = (dp[i][index + 1] + dp[i - 1][0]) % MOD;
				dp[i][index] = (dp[i - 1][index] + 1) % MOD;
			}
			else {
				dp[i][index] = (dp[i][index] + dp[i - 1][index - 1]) % MOD;
			}
		}
		
	}
	ll result = 0;
	for (int i = 0; i < 28; i++) {
		result = (result + dp[n][i]) % MOD;
	}
	cout << result << endl;

	return 0;
}