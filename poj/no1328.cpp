#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
typedef pair<double, double> Pair;

int tt;
int n, d;
double x, y;

Pair segments[1001];

bool cmp(Pair p1, Pair p2) {
	return p1.second < p2.second;
}

int solve() {
	
	bool flag = false;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		double delta = sqrt(d*d - y*y);
		segments[i] = make_pair(x - delta, x + delta);
		if (y > d) flag = true;
	}
	if (flag) return -1;
	sort(segments, segments + n, cmp);
	int res = 1;
	double cur = segments[0].second;
	for (int i = 1; i < n; i++) {
		if (segments[i].first <= cur && cur <= segments[i].second) continue;
		else {
			res++;
			cur = segments[i].second;
		}
	}
	return res;
}

int main() {
	tt = 0;
	while (true) {
		cin >> n >> d;
		if (n == 0 && d == 0) break;
		else cout << "Case " << ++tt << ": " << solve() << endl;
	}

	return 0;
}