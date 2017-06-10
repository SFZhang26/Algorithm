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

int main() {
	int n;
	cin >> n;
	double tp = 0;
	double fp = 0;
	double tn = 0;
	double fn = 0;
	for (int i = 0; i < n; i++) {
		char a, b;
		cin >> a >> b;

		if (a == '+') {
			if (b == '+') tp++;
			else fn++;
		}
		else{
			if (b == '+') fp++;
			else tn++;
		}
	}
	double p = tp / (tp + fp);
	double r = tp / (tp + fn);
	double res = 0;
	if (p != 0) {
		res = 2 * p*r / (p + r) * 100;
	}
	cout << fixed;
	cout << setprecision(2) << res << "%" << endl;
	return 0;
}