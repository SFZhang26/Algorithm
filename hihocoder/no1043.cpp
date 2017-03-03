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

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> need(n, 0);
	vector<int> value(n, 0);
	for (int i = 0; i < n; i++) cin >> need[i] >> value[i];
	vector<int> dp(m + 1, 0);
	for (int i = 0; i < n; i++) {
		for (int j = need[i]; j < m + 1; j++) {
			dp[j] = max(dp[j], dp[j - need[i]] + value[i]);
		}
	}
	cout << dp.back() << endl;
	return 0;
}