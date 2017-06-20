#include <cstdio>
#include <cstring>
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
ll l, r, k;
int bit[20];
ll base[20];

struct node {
	ll sum, n;
	node() {
		sum = 0;
		n = -1;
	}
	node(ll s, ll x) {
		sum = s;
		n = x;
	}
};

node dp[20][20][200];

node dfs(int len, int dig, bool same_flag, int sum, bool begin_zero) {
	node t(0, 0);
	if (len <= 0 || len >= 20 || dig < 0 || dig > 9 || sum < -100 || sum >= 100)
		return t;
	if (!same_flag && dp[len][dig + (begin_zero ? 10 : 0)][sum + 100].n != -1)
		return dp[len][dig + (begin_zero ? 10 : 0)][sum + 100];
	if (len == 1) {
		if (dig != sum) return t;
		t.n = 1;
		t.sum = sum;
		return t;
	}
	int top = same_flag ? bit[len - 2] : 9;
	for (int i = 0; i <= top; i++) {
		node temp(0, 0);
		if (begin_zero) {
			temp = dfs(len - 1, i, same_flag && (i == top), sum, i == 0);
		}
		else {
			temp = dfs(len - 1, i, same_flag && (i == top), dig - sum, false);
		}
		t.n += temp.n;
		t.sum = ((t.sum + temp.sum) % MOD + ((temp.n*dig) % MOD *base[len - 1]) % MOD) % MOD;
	}
	if (!same_flag) {
		dp[len][dig + (begin_zero ? 10 : 0)][sum + 100] = t;
	}
	return t;
}

ll solve(ll n, int k) {
	if (n <= 0) return 0;
	int i = 0;
	while (n > 0) {
		bit[i] = n % 10;
		n /= 10;
		i++;
	}
	return dfs(i + 1, 0, true, k, true).sum;
}

int main() {
	cin >> l >> r >> k;
	base[0] = 1;
	for (int i = 1; i < 20; i++) {
		base[i] = (base[i - 1] * 10) % MOD;
	}
	cout << (solve(r, k) - solve(l - 1, k) + MOD) % MOD << endl;
	return 0;
}