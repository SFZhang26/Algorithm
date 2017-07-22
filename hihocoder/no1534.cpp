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

const ll MAX = 100005;

ll n, vec[MAX];
ll sum, k;
ll result;

ll get_num(ll a, ll b, ll c) {
	ll cur = 0;
	a *= c;
	b *= c;
	vector<ll> index_a, index_b;
	ll cur_sum = 0;
	for (ll i = 0; i < n - 1; i++) {
		cur_sum += vec[i];
		if (cur_sum == a) index_a.push_back(i);
		if (cur_sum == (a + b)) index_b.push_back(i);
	}
	int i = 0, j = 0, sa = index_a.size(), sb = index_b.size();
	while (i < sa && j < sb) {
		if (index_a[i] < index_b[j]) {
			cur += (sb - j);
			i++;
		}
		else {
			j++;
		}
	}
	return cur;
}

int main() {
	scanf("%d", &n);
	sum = 0;
	result = 0;
	for (ll i = 0; i < n; i++) {
		scanf("%d", &vec[i]);
		sum += vec[i];
	}
	k = abs(sum) / 3;
	ll flag = 1;
	if (sum < 0) flag = -1;
	if ((abs(sum) % 3) == 0) {
		result += get_num(k, k, flag);
	}
	else if ((abs(sum) % 3) == 1) {
		result += get_num(k + 1, k, flag);
		result += get_num(k, k + 1, flag);
		result += get_num(k, k, flag);
	}
	else {
		result += get_num(k, k + 1, flag);
		result += get_num(k + 1, k, flag);
		result += get_num(k + 1, k + 1, flag);
	}
	cout << result << endl;

	return 0;
}