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

ll a, b, p;
ll x, y;

void extended_euclidean(ll a, ll b) {
	if (b == 0) {
		x = 1;
		y = 0;
		return;
	}
	extended_euclidean(b, a%b);
	ll tmp = x;
	x = y;
	y = tmp - a / b*x;
}

int main() {
	cin >> a >> b >> p;
	extended_euclidean(b, p);
	ll k = (x%p + p) % p;
	cout << (a*k) % p << endl;
	return 0;
}