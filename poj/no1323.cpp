#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int LEN = 1005;
int m, n, t, x;
int a[LEN];
bool visited[LEN];

void fill(int k) {
	int count = 0;
	for (int i = 0; i <= m*n; i++) {
		if (count == k) break;
		if (!visited[i]) {
			count++;
			visited[i] = true;
		}
		if (count == k) break;
	}
}

int solve() {
	for (int i = 0; i < LEN; i++) visited[i] = false;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		visited[a[i]] = true;
	}
	sort(a, a + n);
	int res = 0;
	for (int i = n - 1; i >= 0; i--) {
		int cur = a[i];
		int pos = cur + 1;
		while (pos <= m*n && visited[pos] == true) pos++;
		if (pos <= m*n) {
			visited[pos] = true;
			fill(m - 2);
		}
		else {
			res++;
			fill(m - 1);
		}
	}
	return res;
}

int main() {
	t = 1;
	while (cin >> m >> n) {
		if (m == 0 && n == 0) break;
		else cout << "Case " << t << ": " << solve() << endl;
		t++;
	}

	return 0;
}