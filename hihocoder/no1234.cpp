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

double DELTA = 1e-10;

ll solve(double x) {
	if (x < -DELTA) return 0;
	double cur = 0.0;
	double div = 0.25;
	ll result = 0;
	while (x >= cur) {
		if (abs(x - cur) < DELTA) return -1;
		result += 4;
		cur += div;
		div /= 2.0;
	}
	if (abs(x - cur) < DELTA) return -1;
	return result;
}


int main() {
	cin >> T;
	for (int tt = 0; tt < T; tt++) {
		double x;
		cin >> x;
		cout << solve(x) << endl;

	}

	return 0;
}