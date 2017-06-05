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
int n;
ll result;

ll MOD = 1e9 + 7;

int main() {
	cin >> n;
	result = 0;
	vector<ll> no_a(n + 1, 0);
	no_a[0] = 1;
	no_a[1] = 2;
	ll l0 = 1;
	ll l1 = 1;
	ll l2 = 0;
	for (int i = 2; i <= n; i++) {
		l2 = l1;
		l1 = l0;
		l0 = no_a[i - 1];
		no_a[i] = (l0 + l1 + l2) % MOD;
	}
	for (int i = 0; i < n / 2; i++) 
		result = (result + 2 * no_a[i] * no_a[n - 1 - i]) % MOD;
	if (n % 2 == 1)
		result = (result + no_a[n / 2] * no_a[n / 2]) % MOD;
	result = (result + no_a[n]) % MOD;
	cout << result << endl;
	return 0;
}