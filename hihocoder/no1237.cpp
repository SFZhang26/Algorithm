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

double DELTA = 0;
const int MAXNUM = 20001;
int T;
double a, b, r;

double dist(int x, int y) {
	return sqrt((a - x)*(a - x) + (b - y)*(b - y));
}

int main() {
	cin >> a >> b >> r;
	double far = 0;
	int re_x = -MAXNUM;
	int re_y = -MAXNUM;
	for (int x = a - r - 1; x <= a + r + 1; x++) {
		if (abs(x-a) > r) continue;
		vector<int> y(2, 0);
		y[0] = floor(b + sqrt(r*r - (x - a)*(x - a)));
		y[1] = ceil(b - sqrt(r*r - (x - a)*(x - a)));

		vector<double> d(2, 0);
		d[0] = dist(x, y[0]);
		d[1] = dist(x, y[1]);

		for (int i = 0; i<2; i++) {
			if (d[i] > far) {
				far = d[i];
				re_x = x;
				re_y = y[i];
			}
			else if (abs(d[i] - far) <= DELTA) {
				if (x>re_x) {
					re_x = x;
					re_y = y[i];
				}
				else if (x == re_x && y[i] > re_y) {
					re_y = y[i];
				}
			}
		}
	}
	
	cout << re_x << " " << re_y << endl;
	return 0;
}