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

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a%b);
}

bool solve(ll l, ll f, ll d) {
	if (f > l) return false;
	ll g = gcd(l, d);
	if (f > g) return false;
	for (ll i = 0; i <= l-f; i++) {
		bool flag = true;
		if (((i + f - 1) / g - (i + 1) / g) == 0) return true;
	}
	return false;
}

int main() {
	cin >> T;
	for (int tt = 0; tt < T; tt++) {
		ll l, f, d;
		cin >> l >> f >> d;

		bool result = solve(l, f, d);

		if (result) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}