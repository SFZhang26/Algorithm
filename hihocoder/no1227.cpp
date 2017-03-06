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

int m, n;

int solve(vector<pair<double, double>> location, int m, int n) {
	if (n > m) return -1;
	int result = 10000;
	for (int i = 0; i < m; i++) {
		double x = location[i].first;
		double y = location[i].second;

		vector<double> vec;
		for (int j = 0; j < m; j++) {
			double dist = sqrt((x - location[j].first)*(x - location[j].first) + (y - location[j].second)*(y - location[j].second));
			vec.push_back(dist);
		}
		sort(vec.begin(), vec.end());
		int len = floor(vec[n - 1]) + 1;
		if (n == m) {
			result = min(result, len);
		}
		else {
			if (len >= vec[n]) continue;
			else result = min(result, len);
		}
	}
	return result == 10000 ? -1 : result;
}

int main() {
	cin >> T;
	for (int tt = 0; tt < T; tt++) {
		cin >> m >> n;
		vector<pair<double, double>> location(m, make_pair(0, 0));
		for (int i = 0; i < m; i++) {
			cin >> location[i].first >> location[i].second;
		}
		int result = solve(location, m, n);
		cout << result << endl;
	}
	
	return 0;
}