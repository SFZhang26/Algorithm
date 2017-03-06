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

int m, n;

int main() {
	cin >> n;
	string str;
	cin >> str;
	cin >> m;
	vector<vector<bool>> grid(26, vector<bool>(26, true));
	for (int i = 0; i < m; i++) {
		string temp;
		cin >> temp;
		grid[temp[0] - 'a'][temp[1] - 'a'] = false;
		grid[temp[1] - 'a'][temp[0] - 'a'] = false;
	}
	vector<int> dp(26, 0);
	int l = 1;
	for (int i = 0; i < str.size(); i++) {
		int r = str[i] - 'a';
		int re = 0;
		for (int j = 0; j < 26; j++) {
			if (grid[r][j])	re = max(re, dp[j] + 1);
		}
		dp[r] = re;
	}
	for (int i = 0; i < 26; i++) l = max(l, dp[i]);
	cout << n - l << endl;
	return 0;
}