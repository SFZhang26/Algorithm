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

int T;
ll n, res;
int main() {
	cin >> T;
	ll res = 1;
	for (int tt = 0; tt < T; tt++) {
		cin >> n;
		res = 1;
		n *= 2;
		for (ll a = 2; a <= sqrt(n); a++) {
			ll yu = n%a;
			ll k = n / a;
			if (yu == 0) {
				if (k % 2 == 1) {
					if ((a - (k / 2) * 2) > 0) res = max(res, k);
					if ((k - a + 1) > 0) res = max(res, a);
				}
				else if (a % 2 == 1) {
					if ((k - (a / 2) * 2) > 0) res = max(res, a);
					if ((a - k + 1) > 0) res = max(res, k);
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}