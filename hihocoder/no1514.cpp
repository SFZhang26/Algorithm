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
int n, m, l;

int solve(vector<int> v1, vector<int> v2) {
	int i = 0, j = 0;
	int result = 100000000;
	while (i < v1.size() && j < v2.size()) {
		result = min(result, abs(v1[i] - v2[j]));
		if (v1[i] <= v2[j]) i++;
		else j++;
	}
	return result;
}

int main() {
	cin >> n >> m >> l;
	vector<int> a(n, 0), b(m, 0), c(l, 0);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	for (int i = 0; i < l; i++) cin >> c[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	int result = 100000000;
	int i = 0, j = 0, k = 0;
	while (i < n&&j < m&&k < l) {
		result = min(result, abs(a[i] - b[j]) + abs(b[j] - c[k]) + abs(c[k] - a[i]));
		if (a[i] < b[j] && a[i] < c[k]) i++;
		else if (b[j] < a[i] && b[j] <= c[k]) j++;
		else k++;
	}
	cout << result << endl;
	return 0;
}